#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// global file pointer for report
FILE *report_file = NULL;

// simple pdf to text converter (fallback if pdftotext not available)
void extractTextFromPDF(const char *filename, const char *output) {
    FILE *pdf = fopen(filename, "rb");
    FILE *txt = fopen(output, "w");
    
    if (!pdf || !txt) {
        printf("Error: Cannot process PDF file\n");
        if(pdf) fclose(pdf);
        if(txt) fclose(txt);
        return;
    }
    
    // simple text extraction - just get readable characters
    int c;
    int space_added = 0;
    while ((c = fgetc(pdf)) != EOF) {
        if (isprint(c) && c != '\r') {
            fprintf(txt, "%c", c);
            space_added = 0;
        } else if (!space_added && c != '\r') {
            fprintf(txt, " ");
            space_added = 1;
        }
    }
    
    fclose(pdf);
    fclose(txt);
}

// converts pdf/docx to text file
void convertToText(const char *src, const char *out) {
    if (strstr(src, ".pdf")) {
        // try pdftotext first, if fails use fallback
        char cmd[200];
        sprintf(cmd, "pdftotext \"%s\" \"%s\" 2>/dev/null", src, out);
        int result = system(cmd);
        
        if (result != 0) {
            // pdftotext not available, use basic extraction
            printf("Note: Using basic PDF text extraction\n");
            extractTextFromPDF(src, out);
        }
    }
    else if (strstr(src, ".docx")) {
        char cmd[200];
        sprintf(cmd, "docx2txt \"%s\" \"%s\" 2>/dev/null", src, out);
        int result = system(cmd);
        
        if (result != 0) {
            printf("Warning: docx2txt not installed, trying to read as text\n");
        }
    }
}

// reads file and handles pdf/docx conversion
char* readFile(char *filename) {
    char tempFile[] = "temp_converted.txt";
    char *actualFile = filename;
    
    // if pdf or docx, convert it first
    if (strstr(filename, ".pdf") || strstr(filename, ".docx")) {
        convertToText(filename, tempFile);
        actualFile = tempFile;
    }
    
    FILE *fp = fopen(actualFile, "r");
    
    if (!fp) {
        printf("cant open file %s\n", filename);
        return NULL;
    }
    
    fseek(fp, 0, SEEK_END);
    long len = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    char *text = (char*)malloc(len + 10);
    fread(text, 1, len, fp);
    text[len] = '\0';
    
    fclose(fp);
    return text;
}

// makes text lowercase and removes punctuation stuff
void preprocessText(char *src, char *dest) {
    int i = 0, j = 0;
    
    while (src[i] != '\0') {
        char c = src[i];
        if (isupper(c)) c = tolower(c);
        
        // keep only letters numbers and spaces
        if (isalnum(c) || c == ' ') 
            dest[j++] = c;
        else 
            dest[j++] = ' ';
        
        i++;
    }
    dest[j] = '\0';
    
    // remove multiple spaces
    i = 0; j = 0;
    int space_flag = 0;
    while (dest[i] != '\0') {
        if (dest[i] != ' ') {
            dest[j++] = dest[i];
            space_flag = 0;
        } else {
            if (!space_flag) {
                dest[j++] = ' ';
                space_flag = 1;
            }
        }
        i++;
    }
    
    if (j > 0 && dest[j - 1] == ' ') j--;
    dest[j] = '\0';
}

// checking plagiarism - compares 3 word chunks
float checkPlgText(char *txt1, char *txt2) {
    // BUG FIX: make copies because strtok destroys strings
    char *copy1 = (char*)malloc(strlen(txt1) + 1);
    char *copy2 = (char*)malloc(strlen(txt2) + 1);
    strcpy(copy1, txt1);
    strcpy(copy2, txt2);
    
    int max1 = 100, max2 = 100;
    
    char **tokens1 = (char**)malloc(max1 * sizeof(char*));
    int t1 = 0;
    
    char *w1 = strtok(copy1, " ");
    while (w1 != NULL) {
        if (t1 >= max1) {
            max1 = max1 * 2;
            tokens1 = realloc(tokens1, max1 * sizeof(char*));
        }
        tokens1[t1] = (char*)malloc(strlen(w1) + 1);
        strcpy(tokens1[t1], w1);
        t1++;
        w1 = strtok(NULL, " ");
    }
    
    char **tokens2 = malloc(max2 * sizeof(char*));
    int t2 = 0;
    
    char *w2 = strtok(copy2, " ");
    while (w2 != NULL) {
        if (t2 >= max2) {
            max2 = max2 * 2;
            tokens2 = realloc(tokens2, max2 * sizeof(char*));
        }
        tokens2[t2] = malloc(strlen(w2) + 1);
        strcpy(tokens2[t2], w2);
        t2++;
        w2 = strtok(NULL, " ");
    }
    
    free(copy1);
    free(copy2);
    
    int n = 3;
    float similarity = 0;
    
    if (t1 >= n && t2 >= n) {
        int ng1 = t1 - n + 1;
        char **ngram1 = malloc(ng1 * sizeof(char*));
        
        int i;
        for (i = 0; i < ng1; i++) {
            int size = strlen(tokens1[i])+strlen(tokens1[i+1])+strlen(tokens1[i+2])+5;
            ngram1[i] = malloc(size);
            sprintf(ngram1[i], "%s %s %s", tokens1[i], tokens1[i+1], tokens1[i+2]);
        }
        
        int ng2 = t2 - n + 1;
        char **ngram2 = malloc(ng2 * sizeof(char*));
        
        for (i = 0; i < ng2; i++) {
            int size = strlen(tokens2[i])+strlen(tokens2[i+1])+strlen(tokens2[i+2])+5;
            ngram2[i] = malloc(size);
            sprintf(ngram2[i], "%s %s %s", tokens2[i], tokens2[i+1], tokens2[i+2]);
        }
        
        int match = 0;
        for (i = 0; i < ng1; i++) {
            int j;
            for (j = 0; j < ng2; j++) {
                if (strcmp(ngram1[i], ngram2[j]) == 0) {
                    match++;
                    
                    // write matched 3-grams to report
                    if(report_file != NULL) {
                        fprintf(report_file, "  - \"%s\"\n", ngram1[i]);
                    }
                    
                    break;
                }
            }
        }
        
        similarity = ((float)match / ng1) * 100;
        
        for (i = 0; i < ng1; i++) free(ngram1[i]);
        free(ngram1);
        for (i = 0; i < ng2; i++) free(ngram2[i]);
        free(ngram2);
    }
    
    int i;
    for (i = 0; i < t1; i++) free(tokens1[i]);
    free(tokens1);
    for (i = 0; i < t2; i++) free(tokens2[i]);
    free(tokens2);
    
    return similarity;
}

// removes comments and include statements from code
void removeCommentsAndHeaders(char *src, char *dest) {
    int i = 0, j = 0;
    
    while (src[i] != '\0') {
        if (src[i] == '#') {
            while (src[i] != '\n' && src[i] != '\0') i++;
            continue;
        }
        
        if (src[i] == '/' && src[i + 1] == '/') {
            i = i + 2;
            while (src[i] != '\n' && src[i] != '\0') i++;
            continue;
        }
        
        if (src[i] == '/' && src[i + 1] == '*') {
            i = i + 2;
            while (!(src[i] == '*' && src[i + 1] == '/') && src[i] != '\0') i++;
            if (src[i] != '\0') i = i + 2;
            continue;
        }
        
        dest[j++] = src[i++];
    }
    dest[j] = '\0';
}

int isKeyword(char *word) {
    char *keywords[] = {"int","float","double","char","void","if","else","while","for","return"};
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

void removeKeywords(char *src, char *dest) {
    int i = 0, j = 0;
    char word[50];
    int w = 0;
    
    while (src[i] != '\0') {
        if (isalpha(src[i])) {
            word[w++] = src[i];
        } else {
            word[w] = '\0';
            if (w > 0 && !isKeyword(word)) {
                int x;
                for (x = 0; word[x] != '\0'; x++)
                    dest[j++] = word[x];
            }
            w = 0;
            dest[j++] = src[i];
        }
        i++;
    }
    dest[j] = '\0';
}

// FIXED: compares code files by matching unique tokens
void sim_chek(char *s1, char *s2) {
    char *copy1 = (char*)malloc(strlen(s1) + 1);
    char *copy2 = (char*)malloc(strlen(s2) + 1);
    strcpy(copy1, s1);
    strcpy(copy2, s2);
    
    // tokenize first file
    int max_tokens = 1000;
    char **tokens1 = (char**)malloc(max_tokens * sizeof(char*));
    int count1 = 0;
    
    char *tok = strtok(copy1, " \n\t");
    while (tok != NULL && count1 < max_tokens) {
        tokens1[count1] = (char*)malloc(strlen(tok) + 1);
        strcpy(tokens1[count1], tok);
        count1++;
        tok = strtok(NULL, " \n\t");
    }
    
    // tokenize second file
    char **tokens2 = (char**)malloc(max_tokens * sizeof(char*));
    int count2 = 0;
    
    tok = strtok(copy2, " \n\t");
    while (tok != NULL && count2 < max_tokens) {
        tokens2[count2] = (char*)malloc(strlen(tok) + 1);
        strcpy(tokens2[count2], tok);
        count2++;
        tok = strtok(NULL, " \n\t");
    }
    
    free(copy1);
    free(copy2);
    
    if(count1 == 0 || count2 == 0) {
        printf("No tokens found!\n");
        // free memory
        int i;
        for(i = 0; i < count1; i++) free(tokens1[i]);
        for(i = 0; i < count2; i++) free(tokens2[i]);
        free(tokens1);
        free(tokens2);
        return;
    }
    
    // BUG FIX: track which tokens from file2 are already matched
    int *matched = (int*)calloc(count2, sizeof(int));
    int total_matches = 0;
    
    // compare tokens
    int i, j;
    for (i = 0; i < count1; i++) {
        for (j = 0; j < count2; j++) {
            // only match if not already matched
            if (!matched[j] && strcmp(tokens1[i], tokens2[j]) == 0) {
                printf("Matched: %s\n", tokens1[i]);
                
                // write to report file if open
                if(report_file != NULL) {
                    fprintf(report_file, "  - %s\n", tokens1[i]);
                }
                
                matched[j] = 1; // mark as matched
                total_matches++;
                break;
            }
        }
    }
    
    printf("\nTOTAL MATCHED: %d\n", total_matches);
    float perc = (total_matches / (float)count1) * 100;
    printf("SIMILARITY PERCENTAGE: %.2f%%\n", perc);
    
    // write summary to report
    if(report_file != NULL) {
        fprintf(report_file, "\nTotal Matches: %d\n", total_matches);
        fprintf(report_file, "Similarity: %.2f%%\n", perc);
        fprintf(report_file, "========================================\n\n");
    }
    
    // cleanup
    for(i = 0; i < count1; i++) free(tokens1[i]);
    for(i = 0; i < count2; i++) free(tokens2[i]);
    free(tokens1);
    free(tokens2);
    free(matched);
}

int main() {
    
    printf("\n========================================\n");
    printf("   PLAGIARISM CHECKER SYSTEM\n");
    printf("   FAST NUCES Peshawar\n");
    printf("========================================\n");
    
    while (1) {
        printf("\n========================================\n");
        printf("           MAIN MENU\n");
        printf("========================================\n");
        printf("1. Text File Plagiarism Detection\n");
        printf("2. Code File Plagiarism Detection\n");
        printf("3. Exit\n");
        printf("========================================\n");
        
        int ch;
        printf("Select Option: ");
        scanf("%d", &ch);
        
        if (ch == 1) {
            int n;
            printf("Enter number of text files (2-20): ");
            printf("(supports .txt .pdf .docx)\n");
            scanf("%d", &n);
            
            if (n < 2 || n > 20) {
                printf("Invalid number of files.\n");
                continue;
            }
            
            char filenames[20][100];
            int i;
            for (i = 0; i < n; i++) {
                printf("Enter filename %d: ", i + 1);
                scanf("%s", filenames[i]);
            }
            
            // open report file
            report_file = fopen("plagiarism_report.txt", "a");
            if(report_file != NULL) {
                fprintf(report_file, "========================================\n");
                fprintf(report_file, "   PLAGIARISM DETECTION REPORT\n");
                fprintf(report_file, "   Text File Analysis\n");
                fprintf(report_file, "========================================\n\n");
            }
            
            char *raw[20];
            int files_loaded = 0;
            for (i = 0; i < n; i++) {
                raw[i] = readFile(filenames[i]);
                if (raw[i] == NULL) {
                    printf("Error reading %s\n", filenames[i]);
                    // free already loaded files
                    int k;
                    for (k = 0; k < i; k++) free(raw[k]);
                    files_loaded = -1;
                    break;
                }
            }
            
            if(files_loaded == -1) {
                if(report_file != NULL) fclose(report_file);
                continue;
            }
            
            char pre1[20][5000];
            for (i = 0; i < n; i++) {
                preprocessText(raw[i], pre1[i]);
            }
            
            // comparing all files
            for (i = 0; i < n; i++) {
                int j;
                for (j = i + 1; j < n; j++) {
                    printf("\n--- Comparing %s and %s ---\n", filenames[i], filenames[j]);
                    
                    // write to report
                    if(report_file != NULL) {
                        fprintf(report_file, "Comparing: %s vs %s\n", filenames[i], filenames[j]);
                        fprintf(report_file, "Matched 3-word phrases:\n");
                    }
                    
                    // BUG FIX: pass copies to checkPlgText
                    char copy1[5000], copy2[5000];
                    strcpy(copy1, pre1[i]);
                    strcpy(copy2, pre1[j]);
                    
                    float sim = checkPlgText(copy1, copy2);
                    printf("Similarity = %.2f%%\n", sim);
                    
                    // write summary
                    if(report_file != NULL) {
                        fprintf(report_file, "\nSimilarity Score: %.2f%%\n", sim);
                        fprintf(report_file, "========================================\n\n");
                    }
                }
            }
            
            for (i = 0; i < n; i++) free(raw[i]);
            
            // close report
            if(report_file != NULL) {
                fclose(report_file);
                report_file = NULL;
                printf("\nReport saved to: plagiarism_report.txt\n");
            }
        }
        
        else if (ch == 2) {
            int n;
            printf("Enter number of code files (2-20): ");
            scanf("%d", &n);
            
            if (n < 2 || n > 20) {
                printf("Invalid number of files.\n");
                continue;
            }
            
            char filenames[20][100];
            int i;
            for (i = 0; i < n; i++) {
                printf("Enter code filename %d: ", i + 1);
                scanf("%s", filenames[i]);
            }
            
            // open report file
            report_file = fopen("code_plagiarism_report.txt", "a");
            if(report_file != NULL) {
                fprintf(report_file, "========================================\n");
                fprintf(report_file, "   PLAGIARISM DETECTION REPORT\n");
                fprintf(report_file, "   Code File Analysis\n");
                fprintf(report_file, "========================================\n\n");
            }
            
            char *raw[20];
            int files_loaded = 0;
            for (i = 0; i < n; i++) {
                raw[i] = readFile(filenames[i]);
                if (raw[i] == NULL) {
                    printf("Error reading %s\n", filenames[i]);
                    int k;
                    for (k = 0; k < i; k++) free(raw[k]);
                    files_loaded = -1;
                    break;
                }
            }
            
            if(files_loaded == -1) {
                if(report_file != NULL) fclose(report_file);
                continue;
            }
            
            char step[20][5000], final[20][5000];
            for (i = 0; i < n; i++) {
                removeCommentsAndHeaders(raw[i], step[i]);
                removeKeywords(step[i], final[i]);
            }
            
            for (i = 0; i < n; i++) {
                int j;
                for (j = i + 1; j < n; j++) {
                    printf("\n----- COMPARING %s and %s -----\n", filenames[i], filenames[j]);
                    
                    // write to report
                    if(report_file != NULL) {
                        fprintf(report_file, "Comparing: %s vs %s\n", filenames[i], filenames[j]);
                        fprintf(report_file, "Matched tokens:\n");
                    }
                    
                    // BUG FIX: pass copies because sim_chek uses strtok which destroys strings
                    char copy_final1[5000], copy_final2[5000];
                    strcpy(copy_final1, final[i]);
                    strcpy(copy_final2, final[j]);
                    
                    sim_chek(copy_final1, copy_final2);
                }
            }
            
            for (i = 0; i < n; i++) free(raw[i]);
            
            // close report
            if(report_file != NULL) {
                fclose(report_file);
                report_file = NULL;
                printf("\nReport saved to: code_plagiarism_report.txt\n");
            }
        }
        
        else if (ch == 3) {
            printf("Exiting...\n");
            break;
        }
        
        else {
            printf("Invalid option! Try again.\n");
        }
    }
    
    return 0;
}