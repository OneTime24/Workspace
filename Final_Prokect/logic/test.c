#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Define maximum limits for arrays and strings
#define MAX_FILES 50          // Maximum number of files that can be compared
#define MAX_FILENAME 200      // Maximum length of filename
#define MAX_CONTENT 50000     // Maximum size of file content
#define MAX_TOKENS 10000      // Maximum number of tokens in a file
#define MAX_NGRAMS 10000      // Maximum number of n-grams
#define NGRAM_SIZE 3          // Size of n-gram (3 words)

// Structure to store information about each file
typedef struct {
    char filename[MAX_FILENAME];      // Name of the file
    char content[MAX_CONTENT];        // Original file content
    char processed[MAX_CONTENT];      // Processed/cleaned content
} FileData;

// Structure to store n-grams (sequences of words) for text comparison
typedef struct {
    char ngrams[MAX_NGRAMS][200];     // Array to store each n-gram
    int count;                         // Total number of n-grams
} NgramSet;

// Structure to store tokens and their frequencies for code comparison
typedef struct {
    char tokens[MAX_TOKENS][100];     // Array to store unique tokens
    int frequency[MAX_TOKENS];         // Frequency of each token
    int count;                         // Total number of unique tokens
} TokenSet;

// Function declarations (prototypes)
void displayMenu();
void textPlagiarismMode();
void codePlagiarismMode();
void preprocessText(char *text, char *output);
void generateNgrams(char *text, NgramSet *ngrams);
float compareNgrams(NgramSet *set1, NgramSet *set2);
void normalizeCode(char *code, char *output);
void tokenizeCode(char *code, TokenSet *tokens);
float cosineSimilarity(TokenSet *tokens1, TokenSet *tokens2);
void displaySimilarityMatrix(float matrix[][MAX_FILES], int fileCount, FileData files[]);
void removeComments(char *code, char *output);
int isKeyword(char *word);
void clearInputBuffer();

// Main function - entry point of the program
int main() {
    int choice;
    
    // Display welcome header
    printf("\n");
    printf("========================================\n");
    printf("   PLAGIARISM CHECKER SYSTEM\n");
    printf("   FAST NUCES Peshawar\n");
    printf("========================================\n");
    
    // Main program loop - continues until user exits
    while(1) {
        displayMenu();
        printf("\nEnter your choice: ");
        
        // Read user choice with error checking
        if(scanf("%d", &choice) != 1) {
            clearInputBuffer();
            printf("\nInvalid input! Please enter a number.\n");
            continue;
        }
        clearInputBuffer(); // Clear remaining newline character
        
        // Process user's menu choice
        switch(choice) {
            case 1:
                textPlagiarismMode();
                break;
            case 2:
                codePlagiarismMode();
                break;
            case 3:
                printf("\nThank you for using Plagiarism Checker!\n");
                printf("Team: Mohsin Ali, Momina Ahmad, Amna Maqsood\n\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter 1, 2, or 3.\n");
        }
    }
    
    return 0;
}

// Display the main menu options
void displayMenu() {
    printf("\n========================================\n");
    printf("           MAIN MENU\n");
    printf("========================================\n");
    printf("1. Text File Plagiarism Detection\n");
    printf("2. Code File Plagiarism Detection\n");
    printf("3. Exit\n");
    printf("========================================\n");
}

// Clear input buffer to prevent scanf issues
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// TEXT PLAGIARISM DETECTION MODE
void textPlagiarismMode() {
    int fileCount, i, j;
    FileData files[MAX_FILES];              // Array to store all file data
    NgramSet ngramSets[MAX_FILES];          // Array to store n-grams for each file
    float similarityMatrix[MAX_FILES][MAX_FILES];  // 2D array to store similarity scores
    FILE *fp;
    
    printf("\n========================================\n");
    printf("  TEXT PLAGIARISM DETECTION MODE\n");
    printf("========================================\n");
    printf("Enter number of text files (2-%d): ", MAX_FILES);
    
    // Get number of files with validation
    if(scanf("%d", &fileCount) != 1) {
        clearInputBuffer();
        printf("Invalid input!\n");
        return;
    }
    clearInputBuffer();
    
    // Validate file count
    if(fileCount < 2 || fileCount > MAX_FILES) {
        printf("Error: Please enter between 2 and %d files.\n", MAX_FILES);
        return;
    }
    
    printf("\n--- Loading Files ---\n");
    
    // STEP 1: Read all text files
    for(i = 0; i < fileCount; i++) {
        printf("Enter filename %d (e.g., file1.txt): ", i + 1);
        
        // Read filename safely
        if(fgets(files[i].filename, MAX_FILENAME, stdin) == NULL) {
            printf("Error reading filename!\n");
            return;
        }
        
        // Remove newline character from filename
        files[i].filename[strcspn(files[i].filename, "\n")] = '\0';
        
        // Try to open the file
        fp = fopen(files[i].filename, "r");
        if(fp == NULL) {
            printf("Error: Cannot open file '%s'. Please check if file exists.\n", 
                   files[i].filename);
            return;
        }
        
        // Read entire file content
        files[i].content[0] = '\0';  // Initialize as empty string
        char line[1000];
        
        // Read file line by line
        while(fgets(line, sizeof(line), fp) != NULL) {
            // Check if adding this line would exceed buffer
            if(strlen(files[i].content) + strlen(line) < MAX_CONTENT - 1) {
                strcat(files[i].content, line);
            } else {
                printf("Warning: File '%s' too large, truncating...\n", files[i].filename);
                break;
            }
        }
        fclose(fp);
        
        // Check if file is empty
        if(strlen(files[i].content) == 0) {
            printf("Error: File '%s' is empty!\n", files[i].filename);
            return;
        }
        
        // STEP 2: Preprocess the text (clean and normalize)
        preprocessText(files[i].content, files[i].processed);
        
        // STEP 3: Generate n-grams from processed text
        generateNgrams(files[i].processed, &ngramSets[i]);
        
        printf("  ✓ '%s' loaded - %d n-grams generated\n", 
               files[i].filename, ngramSets[i].count);
    }
    
    // STEP 4: Compare all file pairs
    printf("\n--- Calculating Similarities ---\n");
    
    for(i = 0; i < fileCount; i++) {
        for(j = 0; j < fileCount; j++) {
            if(i == j) {
                // Same file - 100% similar to itself
                similarityMatrix[i][j] = 100.0;
            } else if(i < j) {
                // Calculate similarity only once for each pair
                similarityMatrix[i][j] = compareNgrams(&ngramSets[i], &ngramSets[j]);
                similarityMatrix[j][i] = similarityMatrix[i][j];  // Mirror the value
            }
        }
    }
    
    // STEP 5: Display results
    displaySimilarityMatrix(similarityMatrix, fileCount, files);
    
    // STEP 6: Highlight suspicious pairs (>40% similarity threshold)
    printf("\n========================================\n");
    printf("  SUSPICIOUS PAIRS (>40%% similarity)\n");
    printf("========================================\n");
    
    int foundSuspicious = 0;
    for(i = 0; i < fileCount; i++) {
        for(j = i + 1; j < fileCount; j++) {
            if(similarityMatrix[i][j] > 40.0) {
                printf("⚠ WARNING: '%s' <-> '%s'\n", 
                       files[i].filename, files[j].filename);
                printf("   Similarity: %.2f%%\n\n", similarityMatrix[i][j]);
                foundSuspicious = 1;
            }
        }
    }
    
    if(!foundSuspicious) {
        printf("✓ No suspicious pairs found. All files appear original.\n");
    }
    printf("========================================\n");
}

// CODE PLAGIARISM DETECTION MODE
void codePlagiarismMode() {
    int fileCount, i, j;
    FileData files[MAX_FILES];              // Array to store all file data
    TokenSet tokenSets[MAX_FILES];          // Array to store tokens for each file
    float similarityMatrix[MAX_FILES][MAX_FILES];  // 2D array to store similarity scores
    FILE *fp;
    
    printf("\n========================================\n");
    printf("  CODE PLAGIARISM DETECTION MODE\n");
    printf("========================================\n");
    printf("Enter number of code files (2-%d): ", MAX_FILES);
    
    // Get number of files with validation
    if(scanf("%d", &fileCount) != 1) {
        clearInputBuffer();
        printf("Invalid input!\n");
        return;
    }
    clearInputBuffer();
    
    // Validate file count
    if(fileCount < 2 || fileCount > MAX_FILES) {
        printf("Error: Please enter between 2 and %d files.\n", MAX_FILES);
        return;
    }
    
    printf("\n--- Loading Code Files ---\n");
    
    // STEP 1: Read all code files
    for(i = 0; i < fileCount; i++) {
        printf("Enter code filename %d (e.g., program1.c): ", i + 1);
        
        // Read filename safely
        if(fgets(files[i].filename, MAX_FILENAME, stdin) == NULL) {
            printf("Error reading filename!\n");
            return;
        }
        
        // Remove newline character
        files[i].filename[strcspn(files[i].filename, "\n")] = '\0';
        
        // Try to open the file
        fp = fopen(files[i].filename, "r");
        if(fp == NULL) {
            printf("Error: Cannot open file '%s'. Please check if file exists.\n", 
                   files[i].filename);
            return;
        }
        
        // Read entire file content
        files[i].content[0] = '\0';
        char line[1000];
        
        while(fgets(line, sizeof(line), fp) != NULL) {
            if(strlen(files[i].content) + strlen(line) < MAX_CONTENT - 1) {
                strcat(files[i].content, line);
            } else {
                printf("Warning: File '%s' too large, truncating...\n", files[i].filename);
                break;
            }
        }
        fclose(fp);
        
        // Check if file is empty
        if(strlen(files[i].content) == 0) {
            printf("Error: File '%s' is empty!\n", files[i].filename);
            return;
        }
        
        // STEP 2: Normalize the code (remove comments, replace variables)
        normalizeCode(files[i].content, files[i].processed);
        
        // STEP 3: Tokenize normalized code
        tokenizeCode(files[i].processed, &tokenSets[i]);
        
        printf("  ✓ '%s' loaded - %d unique tokens found\n", 
               files[i].filename, tokenSets[i].count);
    }
    
    // STEP 4: Compare all code file pairs using cosine similarity
    printf("\n--- Calculating Similarities ---\n");
    
    for(i = 0; i < fileCount; i++) {
        for(j = 0; j < fileCount; j++) {
            if(i == j) {
                similarityMatrix[i][j] = 100.0;
            } else if(i < j) {
                similarityMatrix[i][j] = cosineSimilarity(&tokenSets[i], &tokenSets[j]);
                similarityMatrix[j][i] = similarityMatrix[i][j];
            }
        }
    }
    
    // STEP 5: Display results
    displaySimilarityMatrix(similarityMatrix, fileCount, files);
    
    // STEP 6: Highlight suspicious pairs (>60% similarity threshold for code)
    printf("\n========================================\n");
    printf("  SUSPICIOUS PAIRS (>60%% similarity)\n");
    printf("========================================\n");
    
    int foundSuspicious = 0;
    for(i = 0; i < fileCount; i++) {
        for(j = i + 1; j < fileCount; j++) {
            if(similarityMatrix[i][j] > 60.0) {
                printf("⚠ WARNING: '%s' <-> '%s'\n", 
                       files[i].filename, files[j].filename);
                printf("   Similarity: %.2f%%\n\n", similarityMatrix[i][j]);
                foundSuspicious = 1;
            }
        }
    }
    
    if(!foundSuspicious) {
        printf("✓ No suspicious pairs found. All code appears original.\n");
    }
    printf("========================================\n");
}

// Preprocess text: convert to lowercase, remove punctuation, normalize spaces
void preprocessText(char *text, char *output) {
    int i, j = 0;
    int lastWasSpace = 1;  // Track if last character was a space
    
    // Process each character in the input text
    for(i = 0; text[i] != '\0' && j < MAX_CONTENT - 1; i++) {
        if(isalpha(text[i])) {
            // Convert letter to lowercase and add to output
            output[j++] = tolower(text[i]);
            lastWasSpace = 0;
        } 
        else if(isspace(text[i])) {
            // Add single space only if last character wasn't a space
            if(!lastWasSpace && j > 0) {
                output[j++] = ' ';
                lastWasSpace = 1;
            }
        }
        // Ignore all other characters (punctuation, numbers, etc.)
    }
    
    // Remove trailing space if present
    if(j > 0 && output[j-1] == ' ') {
        j--;
    }
    
    output[j] = '\0';  // Null-terminate the string
}

// Generate n-grams (sequences of N consecutive words) from text
void generateNgrams(char *text, NgramSet *ngrams) {
    char *words[MAX_TOKENS];
    int wordCount = 0;
    char textCopy[MAX_CONTENT];
    int i;
    
    // Make a copy since strtok modifies the string
    strncpy(textCopy, text, MAX_CONTENT - 1);
    textCopy[MAX_CONTENT - 1] = '\0';
    
    // STEP 1: Split text into individual words
    char *token = strtok(textCopy, " ");
    while(token != NULL && wordCount < MAX_TOKENS) {
        words[wordCount++] = token;
        token = strtok(NULL, " ");
    }
    
    // STEP 2: Create n-grams by combining consecutive words
    ngrams->count = 0;
    
    // Loop through words and create NGRAM_SIZE word sequences
    for(i = 0; i <= wordCount - NGRAM_SIZE && ngrams->count < MAX_NGRAMS; i++) {
        // Start with first word
        strncpy(ngrams->ngrams[ngrams->count], words[i], 199);
        ngrams->ngrams[ngrams->count][199] = '\0';
        
        // Add remaining words in the n-gram
        for(int j = 1; j < NGRAM_SIZE; j++) {
            strncat(ngrams->ngrams[ngrams->count], " ", 199 - strlen(ngrams->ngrams[ngrams->count]));
            strncat(ngrams->ngrams[ngrams->count], words[i + j], 199 - strlen(ngrams->ngrams[ngrams->count]));
        }
        
        ngrams->count++;
    }
}

// Compare two sets of n-grams and return similarity percentage
float compareNgrams(NgramSet *set1, NgramSet *set2) {
    int matches = 0;
    int i, j;
    
    // If either set is empty, return 0% similarity
    if(set1->count == 0 || set2->count == 0) {
        return 0.0;
    }
    
    // Count how many n-grams from set1 appear in set2
    for(i = 0; i < set1->count; i++) {
        for(j = 0; j < set2->count; j++) {
            if(strcmp(set1->ngrams[i], set2->ngrams[j]) == 0) {
                matches++;
                break;  // Found match, move to next n-gram from set1
            }
        }
    }
    
    // Calculate percentage: (matches / total n-grams) * 100
    return ((float)matches / set1->count) * 100.0;
}

// Check if a word is a C keyword
int isKeyword(char *word) {
    // List of common C keywords to preserve
    char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while",
        "printf", "scanf", "include", "define", "main"
    };
    
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    
    for(int i = 0; i < numKeywords; i++) {
        if(strcmp(word, keywords[i]) == 0) {
            return 1;  // It is a keyword
        }
    }
    
    return 0;  // Not a keyword
}

// Remove single-line and multi-line comments from code
void removeComments(char *code, char *output) {
    int i = 0, j = 0;
    int len = strlen(code);
    
    while(i < len) {
        // Check for single-line comment (//)
        if(code[i] == '/' && i + 1 < len && code[i+1] == '/') {
            // Skip until end of line
            i += 2;
            while(i < len && code[i] != '\n') {
                i++;
            }
            // Keep the newline
            if(i < len && code[i] == '\n') {
                output[j++] = '\n';
                i++;
            }
        }
        // Check for multi-line comment (/* */)
        else if(code[i] == '/' && i + 1 < len && code[i+1] == '*') {
            // Skip until we find */
            i += 2;
            while(i < len - 1) {
                if(code[i] == '*' && code[i+1] == '/') {
                    i += 2;
                    break;
                }
                i++;
            }
        }
        // Regular character - copy it
        else {
            output[j++] = code[i++];
        }
    }
    
    output[j] = '\0';
}

// Normalize code: remove comments, replace variables with placeholders
void normalizeCode(char *code, char *output) {
    char temp[MAX_CONTENT];
    
    // STEP 1: Remove all comments from code
    removeComments(code, temp);
    
    // STEP 2: Process the code to normalize it
    int i = 0, j = 0;
    int len = strlen(temp);
    
    while(i < len && j < MAX_CONTENT - 10) {
        // Handle alphabetic characters and underscores (identifiers)
        if(isalpha(temp[i]) || temp[i] == '_') {
            char word[100];
            int k = 0;
            
            // Extract the complete word
            while(i < len && (isalnum(temp[i]) || temp[i] == '_') && k < 99) {
                word[k++] = temp[i++];
            }
            word[k] = '\0';
            
            // Check if it's a keyword - keep it, otherwise replace with VAR
            if(isKeyword(word)) {
                // Copy keyword as-is
                strcpy(&output[j], word);
                j += strlen(word);
            } else {
                // Replace variable name with placeholder
                strcpy(&output[j], "VAR");
                j += 3;
            }
        }
        // Handle numbers - replace all with NUM
        else if(isdigit(temp[i])) {
            // Skip all digits in the number
            while(i < len && (isdigit(temp[i]) || temp[i] == '.')) {
                i++;
            }
            // Replace entire number with NUM
            strcpy(&output[j], "NUM");
            j += 3;
        }
        // Handle strings - replace with STR
        else if(temp[i] == '"') {
            i++;  // Skip opening quote
            while(i < len && temp[i] != '"') {
                if(temp[i] == '\\') i++;  // Skip escape sequences
                i++;
            }
            if(i < len) i++;  // Skip closing quote
            strcpy(&output[j], "STR");
            j += 3;
        }
        // Handle characters - replace with CHR
        else if(temp[i] == '\'') {
            i++;  // Skip opening quote
            if(i < len && temp[i] == '\\') i++;  // Skip escape char
            if(i < len) i++;  // Skip character
            if(i < len && temp[i] == '\'') i++;  // Skip closing quote
            strcpy(&output[j], "CHR");
            j += 3;
        }
        // Keep operators and special characters
        else if(!isspace(temp[i])) {
            output[j++] = temp[i++];
        }
        // Normalize whitespace - keep single space
        else {
            if(j > 0 && output[j-1] != ' ') {
                output[j++] = ' ';
            }
            i++;
        }
    }
    
    output[j] = '\0';
}

// Tokenize normalized code into unique tokens with frequencies
void tokenizeCode(char *code, TokenSet *tokens) {
    char codeCopy[MAX_CONTENT];
    int i;
    
    // Make a copy since strtok modifies the string
    strncpy(codeCopy, code, MAX_CONTENT - 1);
    codeCopy[MAX_CONTENT - 1] = '\0';
    
    tokens->count = 0;
    
    // Split code into tokens using space, newline, and tab as delimiters
    char *token = strtok(codeCopy, " \n\t\r");
    
    while(token != NULL && tokens->count < MAX_TOKENS) {
        // Check if this token already exists in our list
        int found = -1;
        for(i = 0; i < tokens->count; i++) {
            if(strcmp(tokens->tokens[i], token) == 0) {
                found = i;
                break;
            }
        }
        
        if(found >= 0) {
            // Token exists - increment its frequency
            tokens->frequency[found]++;
        } else {
            // New token - add it to the list
            strncpy(tokens->tokens[tokens->count], token, 99);
            tokens->tokens[tokens->count][99] = '\0';
            tokens->frequency[tokens->count] = 1;
            tokens->count++;
        }
        
        token = strtok(NULL, " \n\t\r");
    }
}

// Calculate cosine similarity between two token sets
float cosineSimilarity(TokenSet *tokens1, TokenSet *tokens2) {
    float dotProduct = 0.0;      // Sum of (freq1 * freq2) for matching tokens
    float magnitude1 = 0.0;       // Square root of sum of squares of freq1
    float magnitude2 = 0.0;       // Square root of sum of squares of freq2
    int i, j;
    
    // Handle empty token sets
    if(tokens1->count == 0 || tokens2->count == 0) {
        return 0.0;
    }
    
    // Calculate dot product and magnitude1
    for(i = 0; i < tokens1->count; i++) {
        int freq1 = tokens1->frequency[i];
        int freq2 = 0;
        
        // Find matching token in tokens2
        for(j = 0; j < tokens2->count; j++) {
            if(strcmp(tokens1->tokens[i], tokens2->tokens[j]) == 0) {
                freq2 = tokens2->frequency[j];
                break;
            }
        }
        
        dotProduct += freq1 * freq2;
        magnitude1 += freq1 * freq1;
    }
    
    // Calculate magnitude2
    for(i = 0; i < tokens2->count; i++) {
        int freq2 = tokens2->frequency[i];
        magnitude2 += freq2 * freq2;
    }
    
    // Calculate magnitudes (square roots)
    magnitude1 = sqrt(magnitude1);
    magnitude2 = sqrt(magnitude2);
    
    // Avoid division by zero
    if(magnitude1 == 0.0 || magnitude2 == 0.0) {
        return 0.0;
    }
    
    // Cosine similarity formula: cos(θ) = (A·B) / (||A|| * ||B||)
    // Convert to percentage
    return (dotProduct / (magnitude1 * magnitude2)) * 100.0;
}

// Display similarity matrix in a formatted table
void displaySimilarityMatrix(float matrix[][MAX_FILES], int fileCount, FileData files[]) {
    int i, j;
    
    printf("\n========================================\n");
    printf("      SIMILARITY MATRIX (%%)\n");
    printf("========================================\n\n");
    
    // Print column headers
    printf("%-20s", "");
    for(i = 0; i < fileCount; i++) {
        printf("File%-2d    ", i + 1);
    }
    printf("\n");
    
    // Print horizontal line
    printf("%-20s", "");
    for(i = 0; i < fileCount; i++) {
        printf("--------  ");
    }
    printf("\n");
    
    // Print each row with file comparisons
    for(i = 0; i < fileCount; i++) {
        printf("File%-2d              ", i + 1);
        for(j = 0; j < fileCount; j++) {
            if(i == j) {
                // Same file - print dash
                printf("   --     ");
            } else {
                // Different files - print similarity percentage
                printf("%6.2f%%  ", matrix[i][j]);
            }
        }
        printf("\n");
    }
    
    printf("\n");
    
    // Print legend showing which file number corresponds to which filename
    printf("File Legend:\n");
    for(i = 0; i < fileCount; i++) {
        printf("  File%d: %s\n", i + 1, files[i].filename);
    }
    printf("\n");
}