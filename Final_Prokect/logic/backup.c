#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
    char* readFile(char *filename) {
        FILE *fp = fopen(filename, "r");
        if (!fp) {
            printf("Error opening %s\n", filename);
            return NULL;
        }

        fseek(fp, 0, SEEK_END);
        long len = ftell(fp);
        fseek(fp, 0, SEEK_SET);

        char *text = malloc(len + 1);
        fread(text, 1, len, fp);
        text[len] = '\0';

        fclose(fp);
        return text;
    }

    void removeCommentsAndHeaders(char *src, char *dest) {
    int i = 0, j = 0;

    while (src[i] != '\0') {

        // -------- Rem ove Headers like #include <stdio.h> --------
        if (src[i] == '#') {  
            while (src[i] != '\n' && src[i] != '\0') i++; 
            continue;
        }

        // -------- Remove // comments --------
        if (src[i] == '/' && src[i+1] == '/') {  
            i += 2;
            while (src[i] != '\n' && src[i] != '\0') i++; 
            continue;
        }

        // -------- Remove /* comments */ --------
        if (src[i] == '/' && src[i+1] == '*') {
            i += 2;
            while (!(src[i] == '*' && src[i+1] == '/') && src[i] != '\0') i++; 
            if (src[i] != '\0') i += 2;
            continue;
        }

        dest[j++] = src[i++];
    }
    dest[j] = '\0';
}

int isKeyword(char *word) {
    char *keywords[] = {"int","float","double","char","void","if","else","while","for","return"};
    for(int k = 0; k < 10; k++) {
        if(strcmp(word, keywords[k]) == 0)
            return 1;
    }
    return 0;
}

void removeKeywords(char *src, char *dest) {
    int i = 0, j = 0;
    char word[50];
    int w = 0;

    while (src[i] != '\0') {

        if (isalpha(src[i])) {  // collect letters as a word
            word[w++] = src[i];
        }
        else {
            word[w] = '\0';

            if (w > 0 && !isKeyword(word)) { // if not keyword -> copy
                for (int x = 0; word[x] != '\0'; x++)
                    dest[j++] = word[x];
            }

            w = 0;
            dest[j++] = src[i];
        }
        i++;
    }
    dest[j] = '\0';
}

//SIMILARITY CHECKER!!!

void sim_chek(char *s1, char *s2){
    char temp1[2000], temp2[2000];
    char copy1[2000], copy2[2000];

    strcpy(temp1, s1);   // used for counting + matching
    strcpy(temp2, s2);
    strcpy(copy1, s1);   // used for counting words
    strcpy(copy2, s2);

    // -------- COUNT TOTAL TOKENS IN s1 --------
    int total = 0;
    char *t = strtok(copy1, " ");
    while(t != NULL){
        total++;
        t = strtok(NULL, " ");
    }

    // -------- MATCH TOKENS --------
    int matches = 0;
    char *tok1 = strtok(temp1, " ");
    while(tok1 != NULL){
        char *tok2 = strtok(temp2, " ");

        while(tok2 != NULL){
            if(strcmp(tok1, tok2) == 0){
                printf("Matched: %s\n", tok1);
                matches++;
                break; // prevent double counting
            }
            tok2 = strtok(NULL, " ");
        }

        strcpy(temp2, s2); // reset temp2 because strtok broke it!
        tok2 = NULL;

        tok1 = strtok(NULL, " ");
    }

    // -------- PERCENTAGE --------
    printf("\nTOTAL MATCHED: %d\n", matches);
    float perc = matches / (float)total * 100;
    printf("SIMILARITY PERCENTAGE: %.2f%%\n", perc);
}

float checkPlg(char *file1, char *file2);        //prototype for text plageirism 
float checkcode(char *file1, char *fil2);           //prototype for code plageirism 
int main(){

    printf("\n");
    printf("========================================\n");
    printf("   PLAGIARISM CHECKER SYSTEM\n");
    printf("   FAST NUCES Peshawar\n");
    printf("========================================\n");

    while(1){
        printf("\n========================================\n");
        printf("           MAIN MENU\n");
        printf("========================================\n");
        printf("1. Text File Plagiarism Detection\n");
        printf("2. Code File Plagiarism Detection\n");
        printf("3. Exit\n");
        printf("========================================\n");

        int ch;
        printf("Select Option: ");
        scanf(" %d",&ch);

        switch(ch){

            case 1: {
                int n;
                printf("Enter number of text files to check (2-20): ");
                scanf("%d", &n);
                if(n < 2 || n > 20){
                    printf("Invalid number of files.\n");
                    break;
                }

                char filenames[20][100];
                for(int i=0;i<n;i++){
                    printf("Enter filename %d: ", i+1);
                    scanf("%s", filenames[i]);
                }

                // Compare each file with all others
                for(int i=0;i<n;i++){
                    for(int j=i+1;j<n;j++){
                        printf("\nComparing %s and %s\n", filenames[i], filenames[j]);
                        float sim = checkPlg(filenames[i], filenames[j]);
                        printf("Similarity = %.2f%%\n", sim);
                    }
                }
                break;
            }

            case 2: {
                int n;
                printf("Enter number of code files to check (2-20): ");
                scanf("%d", &n);
                if(n < 2 || n > 20){
                    printf("Invalid number of files.\n");
                    break;
                }

                char filenames[20][100];
                for(int i=0;i<n;i++){
                    printf("Enter code filename %d: ", i+1);
                    scanf("%s", filenames[i]);
                }

                char *raw[20]; // store raw contents
                for(int i=0;i<n;i++){
                    raw[i] = readFile(filenames[i]);
                    if(raw[i] == NULL){
                        printf("Error reading %s\n", filenames[i]);
                        // free previously allocated
                        for(int k=0;k<i;k++) free(raw[k]);
                        break;
                    }
                }

                char step[20][5000], final[20][5000];

                // normalize all files
                for(int i=0;i<n;i++){
                    removeCommentsAndHeaders(raw[i], step[i]);
                    removeKeywords(step[i], final[i]);
                }

                // compare each with every other
                for(int i=0;i<n;i++){
                    for(int j=i+1;j<n;j++){
                        printf("\n----- COMPARING %s and %s -----\n", filenames[i], filenames[j]);
                        sim_chek(final[i], final[j]);
                    }
                }

                // free memory
                for(int i=0;i<n;i++)
                    free(raw[i]);

                break;
            }

            case 3:
                printf("Exiting...\n");
                return 0;
        }
    }
}

float checkPlg(char *file1, char *file2){
            float similarity = 0;

            FILE *ptr1 = fopen(file1,"r");
            if(ptr1==NULL){
                printf("file1 not opening...\n"); 
                return 0;
            }

            FILE *ptr2 = fopen(file2,"r");
            if(ptr2==NULL){
                printf("file2 not opening...\n");
                fclose(ptr1);
                return 0;
            }

            // getting lengths (sir told me to use fseek)
            fseek(ptr1,0,SEEK_END);
            long len1 = ftell(ptr1);
            fseek(ptr1,0,SEEK_SET);

            fseek(ptr2,0,SEEK_END);
            long len2 = ftell(ptr2);
            fseek(ptr2,0,SEEK_SET);

            // reading file 1
            char *text1 = (char*)malloc(len1+5);
            fread(text1,1,len1,ptr1);
            text1[len1] = '\0';
            fclose(ptr1);

            // reading file 2
            char *text2 = (char*)malloc(len2+5);
            fread(text2,1,len2,ptr2);
            text2[len2] = '\0';
            fclose(ptr2);

            // token arrays (idk a better way yet)
            int max1 = 100;
            char **tokens1 = malloc(max1 * sizeof(char*));
            int t1 = 0;

            char *w1 = strtok(text1," ");
            while(w1!=NULL){
                
                if(t1>=max1){          // if array full (hope this works)
                    max1 = max1 * 2;
                    tokens1 = realloc(tokens1, max1*sizeof(char*));
                }

                tokens1[t1] = malloc(strlen(w1)+1);
                strcpy(tokens1[t1], w1);
                t1++;

                w1 = strtok(NULL," ");
            }

            // token array 2
            int max2 = 100;
            char **tokens2 = malloc(max2 * sizeof(char*));
            int t2 = 0;

            char *w2 = strtok(text2," ");
            while(w2!=NULL){
                if(t2>=max2){
                    max2 = max2 * 2;
                    tokens2 = realloc(tokens2, max2*sizeof(char*));
                }

                tokens2[t2] = malloc(strlen(w2)+1);
                strcpy(tokens2[t2], w2);
                t2++;

                w2 = strtok(NULL," ");
            }

            // just printing to see if working
            printf("Tokens from file1:\n");
            for(int i=0;i<t1;i++){
                printf("%s\n", tokens1[i]);
            }

            printf("\nTokens from file2:\n");
            for(int i=0;i<t2;i++){
                printf("%s\n", tokens2[i]);
            }


            // N-GRAM PART (3 words)
            int n = 3;

            if(t1<n || t2<n){
                printf("\nNot enough words for 3-gram \n");
            }
            else{

                int ng1 = t1 - n + 1;
                char **ngram1 = malloc(ng1 * sizeof(char*));

                for(int i=0;i<ng1;i++){
                    int size = strlen(tokens1[i])+strlen(tokens1[i+1])+strlen(tokens1[i+2])+5;
                    ngram1[i] = malloc(size);
                    sprintf(ngram1[i], "%s %s %s", tokens1[i], tokens1[i+1], tokens1[i+2]);
                }

                int ng2 = t2 - n + 1;
                char **ngram2 = malloc(ng2 * sizeof(char*));

                for(int i=0;i<ng2;i++){
                    int size = strlen(tokens2[i])+strlen(tokens2[i+1])+strlen(tokens2[i+2])+5;
                    ngram2[i] = malloc(size);
                    sprintf(ngram2[i], "%s %s %s", tokens2[i], tokens2[i+1], tokens2[i+2]);
                }

                // comparing
                int match = 0;
                for(int i=0;i<ng1;i++){
                    for(int j=0;j<ng2;j++){
                        if(strcmp(ngram1[i], ngram2[j])==0){
                            match++;
                            break;
                        }
                    }
                }

                similarity = ((float)match/ng1)*100;
                

                // freeing ngrams
                for(int i=0;i<ng1;i++) free(ngram1[i]);
                free(ngram1);

                for(int i=0;i<ng2;i++) free(ngram2[i]);
                free(ngram2);
                

            }

            // freeing tokens
            for(int i=0;i<t1;i++)
                free(tokens1[i]);
            free(tokens1);

            for(int i=0;i<t2;i++)
                free(tokens2[i]);
            free(tokens2);

            free(text1);
            free(text2);
            return similarity;

        }
