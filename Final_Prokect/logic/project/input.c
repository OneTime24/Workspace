#include "input.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void extractTextFromPDF(const char *filename, const char *output) {
    FILE *pdf = fopen(filename, "rb");
    FILE *txt = fopen(output, "w");
    
    if (!pdf || !txt) {
        printf("Error: Cannot process PDF file\n");
        if(pdf) fclose(pdf);
        if(txt) fclose(txt);
        return;
    }
    int c, space = 0;
    while ((c = fgetc(pdf)) != EOF) {
        if (isprint(c) && c != '\r') {
            fprintf(txt, "%c", c);
            space = 0;
        } else if (!space && c != '\r') {
            fprintf(txt, " ");
            space = 1;
        }
    }
    fclose(pdf);
    fclose(txt);
}

void convertToText(const char *src, const char *out) {
    char cmd[200];
    if (strstr(src, ".pdf")) {
        sprintf(cmd, "pdftotext \"%s\" \"%s\" 2>/dev/null", src, out);
        if (system(cmd) != 0) {
            printf("Note: Using basic PDF text extraction\n");
            extractTextFromPDF(src, out);
        }
    }
    else if (strstr(src, ".docx")) {
        sprintf(cmd, "docx2txt \"%s\" \"%s\" 2>/dev/null", src, out);
        if (system(cmd) != 0) {
            printf("Warning: docx2txt not installed\n");
        }
    }
}

char* readFile(char *filename) {
    char tempFile[] = "temp_converted.txt";
    char *actual = filename;
    
    if (strstr(filename, ".pdf") || strstr(filename, ".docx")) {
        convertToText(filename, tempFile);
        actual = tempFile;
    }
    FILE *fp = fopen(actual, "r");
    if (!fp) {
        printf("Cannot open file %s\n", filename);
        return NULL;
    }
    fseek(fp,0,SEEK_END);
    long len = ftell(fp);
    fseek(fp,0,SEEK_SET);
    
    char *text = malloc(len + 10);
    fread(text,1,len,fp);
    text[len]='\0';
    fclose(fp);
    return text;
}

void preprocessText(char *src, char *dest) {
    int i=0,j=0;
    while(src[i]!='\0'){
        char c=src[i];
        if(isupper(c))
         c=tolower(c);
        if(isalnum(c) || c==' ')
            dest[j++]=c;
        else
            dest[j++]=' ';
        i++;
    }
    dest[j]='\0';

    i=0; j=0;
    int space=0;
    while(dest[i]!='\0'){
        if(dest[i]!=' '){
            dest[j++]=dest[i];
            space=0;
        } else if(!space){
            dest[j++]=' ';
            space=1;
        }
        i++;
    }
    if(j>0 && dest[j-1]==' ') j--;
    dest[j]='\0';
    
}
