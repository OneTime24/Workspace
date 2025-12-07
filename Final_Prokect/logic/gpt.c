#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Hey! This file pointer stays open throughout the program
// so we can keep writing to our report without opening/closing constantly
FILE *report_file = NULL;

// Okay so this function is like a backup plan for when pdftotext isn't installed
// It's not perfect but it'll grab whatever readable text it can find in the PDF
void extractTextFromPDF(const char *filename, const char *output) {
    FILE *pdf = fopen(filename, "rb");
    FILE *txt = fopen(output, "w");
    
    // Make sure both files opened properly before we do anything
    if (!pdf || !txt) {
        printf("Error: Cannot process PDF file\n");
        if(pdf) fclose(pdf);
        if(txt) fclose(txt);
        return;
    }
    
    // Go through the PDF byte by byte and pull out anything that looks like text
    // Yeah it's crude but it works in a pinch!
    int c;
    int space_added = 0;
    while ((c = fgetc(pdf)) != EOF) {
        if (isprint(c) && c != '\r') {
            fprintf(txt, "%c", c);
            space_added = 0;
        } else if (!space_added && c != '\r') {
            // Add spaces between words so they don't run together
            fprintf(txt, " ");
            space_added = 1;
        }
    }
    
    fclose(pdf);
    fclose(txt);
}

// This converts PDFs and Word docs into plain text so we can actually analyze them
// First tries using proper tools, then falls back to basic extraction if needed
void convertToText(const char *src, const char *out) {
    if (strstr(src, ".pdf")) {
        // Try the real pdftotext command first (way better than our backup)
        char cmd[200];
        sprintf(cmd, "pdftotext \"%s\" \"%s\" 2>/dev/null", src, out);
        int result = system(cmd);
        
        if (result != 0) {
            // Uh oh, pdftotext not found. Time for plan B
            printf("Note: Using basic PDF text extraction\n");
            extractTextFromPDF(src, out);
        }
    }
    else if (strstr(src, ".docx")) {
        // Same deal with Word docs - try the proper tool first
        char cmd[200];
        sprintf(cmd, "docx2txt \"%s\" \"%s\" 2>/dev/null", src, out);
        int result = system(cmd);
        
        if (result != 0) {
            printf("Warning: docx2txt not installed, trying to read as text\n");
        }
    }
}

// Main file reading function - handles regular text files AND fancy formats
// Returns the entire file contents as one big string
char* readFile(char *filename) {
    char tempFile[] = "temp_converted.txt";
    char *actualFile = filename;
    
    // If it's a PDF or Word doc, convert it to plain text first
    if (strstr(filename, ".pdf") || strstr(filename, ".docx")) {
        convertToText(filename, tempFile);
        actualFile = tempFile;
    }
    
    FILE *fp = fopen(actualFile, "r");
    
    if (!fp) {
        printf("cant open file %s\n", filename);
        return NULL;
    }
    
    // Find out how big the file is so we can allocate enough memory
    fseek(fp, 0, SEEK_END);
    long len = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    // Grab all that memory and read the whole file at once
    char *text = (char*)malloc(len + 10);
    fread(text, 1, len, fp);
    text[len] = '\0';
    
    fclose(fp);
    return text;
}

// This function cleans up text so we can compare apples to apples
// Makes everything lowercase, removes punctuation, normalizes spacing
void preprocessText(char *src, char *dest) {
    int i = 0, j = 0;
    
    while (src[i] != '\0') {
        char c = src[i];
        if (isupper(c)) c = tolower(c);
        
        // Only keep letters, numbers, and spaces - everything else becomes a space
        if (isalnum(c) || c == ' ') 
            dest[j++] = c;
        else 
            dest[j++] = ' ';
        
        i++;
    }
    dest[j] = '\0';
    
    // Now squash multiple spaces down to one
    // Because "hello    world" should match "hello world"
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
    
    // Clean up any trailing space
    if (j > 0 && dest[j - 1] == ' ') j--;
    dest[j] = '\0';
}

// The heart of text plagiarism detection!
// Looks for matching 3-word phrases between two texts
// Why 3 words? Because it's long enough to catch real copying but short enough to be efficient
float checkPlgText(char *txt1, char *txt2) {
    // IMPORTANT: We need to make copies because strtok destroys the original string
    // Learned this the hard way!
    char *copy1 = (char*)malloc(strlen(txt1) + 1);
    char *copy2 = (char*)malloc(strlen(txt2) + 1);
    strcpy(copy1, txt1);
    strcpy(copy2, txt2);
    
    int max1 = 100, max2 = 100;
    
    // Break the first text into individual words
    char **tokens1 = (char**)malloc(max1 * sizeof(char*));
    int t1 = 0;
    
    char *w1 = strtok(copy1, " ");
    while (w1 != NULL) {
        // Dynamically grow our array if we need more space
        if (t1 >= max1) {
            max1 = max1 * 2;
            tokens1 = realloc(tokens1, max1 * sizeof(char*));
        }
        tokens1[t1] = (char*)malloc(strlen(w1) + 1);
        strcpy(tokens1[t1], w1);
        t1++;
        w1 = strtok(NULL, " ");
    }
    
    // Do the same for the second text
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
    
    // n-gram size - we're using 3 words at a time
    int n = 3;
    float similarity = 0;
    
    // Only proceed if both texts have at least 3 words
    if (t1 >= n && t2 >= n) {
        // Create all possible 3-word combinations from first text
        int ng1 = t1 - n + 1;
        char **ngram1 = malloc(ng1 * sizeof(char*));
        
        int i;
        for (i = 0; i < ng1; i++) {
            int size = strlen(tokens1[i])+strlen(tokens1[i+1])+strlen(tokens1[i+2])+5;
            ngram1[i] = malloc(size);
            sprintf(ngram1[i], "%s %s %s", tokens1[i], tokens1[i+1], tokens1[i+2]);
        }
        
        // Same for the second text
        int ng2 = t2 - n + 1;
        char **ngram2 = malloc(ng2 * sizeof(char*));
        
        for (i = 0; i < ng2; i++) {
            int size = strlen(tokens2[i])+strlen(tokens2[i+1])+strlen(tokens2[i+2])+5;
            ngram2[i] = malloc(size);
            sprintf(ngram2[i], "%s %s %s", tokens2[i], tokens2[i+1], tokens2[i+2]);
        }
        
        // Now compare every 3-word phrase from text1 against every phrase from text2
        // When we find a match, log it!
        int match = 0;
        for (i = 0; i < ng1; i++) {
            int j;
            for (j = 0; j < ng2; j++) {
                if (strcmp(ngram1[i], ngram2[j]) == 0) {
                    match++;
                    
                    // Save the matched phrase to our report file
                    if(report_file != NULL) {
                        fprintf(report_file, "  - \"%s\"\n", ngram1[i]);
                    }
                    
                    break;
                }
            }
        }
        
        // Calculate similarity as a percentage
        // More matches = higher plagiarism score
        similarity = ((float)match / ng1) * 100;
        
        // Clean up all the n-grams
        for (i = 0; i < ng1; i++) free(ngram1[i]);
        free(ngram1);
        for (i = 0; i < ng2; i++) free(ngram2[i]);
        free(ngram2);
    }
    
    // Don't forget to free all those tokens!
    int i;
    for (i = 0; i < t1; i++) free(tokens1[i]);
    free(tokens1);
    for (i = 0; i < t2; i++) free(tokens2[i]);
    free(tokens2);
    
    return similarity;
}

// Strips out comments and #include statements from code
// Because we don't want those affecting our plagiarism detection
void removeCommentsAndHeaders(char *src, char *dest) {
    int i = 0, j = 0;
    
    while (src[i] != '\0') {
        // Skip preprocessor directives like #include
        if (src[i] == '#') {
            while (src[i] != '\n' && src[i] != '\0') i++;
            continue;
        }
        
        // Skip single-line comments //
        if (src[i] == '/' && src[i + 1] == '/') {
            i = i + 2;
            while (src[i] != '\n' && src[i] != '\0') i++;
            continue;
        }
        
        // Skip multi-line comments /* ... */
        if (src[i] == '/' && src[i + 1] == '*') {
            i = i + 2;
            while (!(src[i] == '*' && src[i + 1] == '/') && src[i] != '\0') i++;
            if (src[i] != '\0') i = i + 2;
            continue;
        }
        
        // Keep everything else
        dest[j++] = src[i++];
    }
    dest[j] = '\0';
}

// Check if a word is a C keyword
// We ignore these because everyone uses "int", "if", "while" etc.
int isKeyword(char *word) {
    char *keywords[] = {"int","float","double","char","void","if","else","while","for","return"};
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Remove all C keywords from the code
// This way we only compare meaningful identifiers and logic
void removeKeywords(char *src, char *dest) {
    int i = 0, j = 0;
    char word[50];
    int w = 0;
    
    while (src[i] != '\0') {
        if (isalpha(src[i])) {
            // Build up a word letter by letter
            word[w++] = src[i];
        } else {
            word[w] = '\0';
            // If it's not a keyword, keep it
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

// Code plagiarism checker - compares tokens between two code files
// Each unique token match increases the similarity score
void sim_chek(char *s1, char *s2) {
    // Again, make copies because strtok is destructive
    char *copy1 = (char*)malloc(strlen(s1) + 1);
    char *copy2 = (char*)malloc(strlen(s2) + 1);
    strcpy(copy1, s1);
    strcpy(copy2, s2);
    
    // Break first file into tokens (words, operators, etc.)
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
    
    // Same for second file
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
    
    // Sanity check - make sure we actually got some tokens
    if(count1 == 0 || count2 == 0) {
        printf("No tokens found!\n");
        // Don't forget to clean up even when things go wrong
        int i;
        for(i = 0; i < count1; i++) free(tokens1[i]);
        for(i = 0; i < count2; i++) free(tokens2[i]);
        free(tokens1);
        free(tokens2);
        return;
    }
    
    // This array tracks which tokens from file2 we've already matched
    // Prevents double-counting the same match
    int *matched = (int*)calloc(count2, sizeof(int));
    int total_matches = 0;
    
    // Compare every token from file1 against every token from file2
    int i, j;
    for (i = 0; i < count1; i++) {
        for (j = 0; j < count2; j++) {
            // Only count each token once!
            if (!matched[j] && strcmp(tokens1[i], tokens2[j]) == 0) {
                printf("Matched: %s\n", tokens1[i]);
                
                // Log it to the report
                if(report_file != NULL) {
                    fprintf(report_file, "  - %s\n", tokens1[i]);
                }
                
                matched[j] = 1; // Mark this one as used
                total_matches++;
                break;
            }
        }
    }
    
    // Show the results
    printf("\nTOTAL MATCHED: %d\n", total_matches);
    float perc = (total_matches / (float)count1) * 100;
    printf("SIMILARITY PERCENTAGE: %.2f%%\n", perc);
    
    // Write summary to report file
    if(report_file != NULL) {
        fprintf(report_file, "\nTotal Matches: %d\n", total_matches);
        fprintf(report_file, "Similarity: %.2f%%\n", perc);
        fprintf(report_file, "========================================\n\n");
    }
    
    // Always clean up your memory!
    for(i = 0; i < count1; i++) free(tokens1[i]);
    for(i = 0; i < count2; i++) free(tokens2[i]);
    free(tokens1);
    free(tokens2);
    free(matched);
}

// This function handles ALL text file plagiarism checking and report generation
// Takes in file names and count, does all the work, generates report
void checkTextPlagiarism(char filenames[][100], int n) {
    // Open our report file so we can save everything
    report_file = fopen("plagiarism_report.txt", "a");
    if(report_file != NULL) {
        fprintf(report_file, "========================================\n");
        fprintf(report_file, "   PLAGIARISM DETECTION REPORT\n");
        fprintf(report_file, "   Text File Analysis\n");
        fprintf(report_file, "========================================\n\n");
    }
    
    // Read all the files into memory
    char *raw[20];
    int files_loaded = 0;
    int i;
    for (i = 0; i < n; i++) {
        raw[i] = readFile(filenames[i]);
        if (raw[i] == NULL) {
            printf("Error reading %s\n", filenames[i]);
            // If one fails, clean up what we already loaded
            int k;
            for (k = 0; k < i; k++) free(raw[k]);
            files_loaded = -1;
            break;
        }
    }
    
    // If file loading failed, bail out
    if(files_loaded == -1) {
        if(report_file != NULL) fclose(report_file);
        return;
    }
    
    // Clean up all the text files (lowercase, remove punctuation, etc.)
    char pre1[20][5000];
    for (i = 0; i < n; i++) {
        preprocessText(raw[i], pre1[i]);
    }
    
    // Now compare every file against every other file
    // This is why we need n*(n-1)/2 comparisons
    for (i = 0; i < n; i++) {
        int j;
        for (j = i + 1; j < n; j++) {
            printf("\n--- Comparing %s and %s ---\n", filenames[i], filenames[j]);
            
            // Write comparison header to report
            if(report_file != NULL) {
                fprintf(report_file, "Comparing: %s vs %s\n", filenames[i], filenames[j]);
                fprintf(report_file, "Matched 3-word phrases:\n");
            }
            
            // Make copies before passing to checkPlgText (because strtok)
            char copy1[5000], copy2[5000];
            strcpy(copy1, pre1[i]);
            strcpy(copy2, pre1[j]);
            
            // Do the actual comparison!
            float sim = checkPlgText(copy1, copy2);
            printf("Similarity = %.2f%%\n", sim);
            
            // Write results to report
            if(report_file != NULL) {
                fprintf(report_file, "\nSimilarity Score: %.2f%%\n", sim);
                fprintf(report_file, "========================================\n\n");
            }
        }
    }
    
    // Free all the raw file contents
    for (i = 0; i < n; i++) free(raw[i]);
    
    // Close the report and let user know where to find it
    if(report_file != NULL) {
        fclose(report_file);
        report_file = NULL;
        printf("\nReport saved to: plagiarism_report.txt\n");
    }
}

// This function handles ALL code file plagiarism checking and report generation
// Takes in file names and count, does all the work, generates report
void checkCodePlagiarism(char filenames[][100], int n) {
    // Open report for code analysis
    report_file = fopen("code_plagiarism_report.txt", "a");
    if(report_file != NULL) {
        fprintf(report_file, "========================================\n");
        fprintf(report_file, "   PLAGIARISM DETECTION REPORT\n");
        fprintf(report_file, "   Code File Analysis\n");
        fprintf(report_file, "========================================\n\n");
    }
    
    // Load all code files
    char *raw[20];
    int files_loaded = 0;
    int i;
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
        return;
    }
    
    // Two-step cleaning process for code:
    // 1. Remove comments and headers
    // 2. Remove keywords
    // This leaves us with just the unique identifiers and structure
    char step[20][5000], final[20][5000];
    for (i = 0; i < n; i++) {
        removeCommentsAndHeaders(raw[i], step[i]);
        removeKeywords(step[i], final[i]);
    }
    
    // Compare all pairs of code files
    for (i = 0; i < n; i++) {
        int j;
        for (j = i + 1; j < n; j++) {
            printf("\n----- COMPARING %s and %s -----\n", filenames[i], filenames[j]);
            
            // Log to report
            if(report_file != NULL) {
                fprintf(report_file, "Comparing: %s vs %s\n", filenames[i], filenames[j]);
                fprintf(report_file, "Matched tokens:\n");
            }
            
            // Make copies (yep, strtok strikes again)
            char copy_final1[5000], copy_final2[5000];
            strcpy(copy_final1, final[i]);
            strcpy(copy_final2, final[j]);
            
            // Run the similarity check
            sim_chek(copy_final1, copy_final2);
        }
    }
    
    // Clean up
    for (i = 0; i < n; i++) free(raw[i]);
    
    // Close report
    if(report_file != NULL) {
        fclose(report_file);
        report_file = NULL;
        printf("\nReport saved to: code_plagiarism_report.txt\n");
    }
}

int main() {
    
    // Welcome screen - make it look nice!
    printf("\n========================================\n");
    printf("   PLAGIARISM CHECKER SYSTEM\n");
    printf("   FAST NUCES Peshawar\n");
    printf("========================================\n");
    
    // Main program loop - keeps running until user chooses to exit
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
        
        // Option 1: Check text files (essays, documents, etc.)
        if (ch == 1) {
            int n;
            printf("Enter number of text files (2-20): ");
            printf("(supports .txt .pdf .docx)\n");
            scanf("%d", &n);
            
            // Make sure they gave us a reasonable number
            if (n < 2 || n > 20) {
                printf("Invalid number of files.\n");
                continue;
            }
            
            // Get all the filenames from the user
            char filenames[20][100];
            int i;
            for (i = 0; i < n; i++) {
                printf("Enter filename %d: ", i + 1);
                scanf("%s", filenames[i]);
            }
            
            // Call the function to do all the work!
            checkTextPlagiarism(filenames, n);
        }
        
        // Option 2: Check code files (C, Java, Python, etc.)
        else if (ch == 2) {
            int n;
            printf("Enter number of code files (2-20): ");
            scanf("%d", &n);
            
            if (n < 2 || n > 20) {
                printf("Invalid number of files.\n");
                continue;
            }
            
            // Get filenames
            char filenames[20][100];
            int i;
            for (i = 0; i < n; i++) {
                printf("Enter code filename %d: ", i + 1);
                scanf("%s", filenames[i]);
            }
            
            // Call the function to do all the work!
            checkCodePlagiarism(filenames, n);
        }
        
        // Option 3: Exit the program
        else if (ch == 3) {
            printf("Exiting...\n");
            break;
        }
        
        // Invalid choice - just loop back to menu
        else {
            printf("Invalid option! Try again.\n");
        }
    }
    
    return 0;
}