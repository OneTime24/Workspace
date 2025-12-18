#ifndef PLAGIARISM_H
#define PLAGIARISM_H

#include <stdio.h>          // printf() scanf()                                
#include <ctype.h>           //tolower() | atof() | atoi()  |   alpha()        
#include <string.h>          // strcmp()  strtok()  
#include <stdlib.h>           // malloc calloc  realloc()      system()
     

// Global file pointer for the report      
extern FILE *fp_rep;              

// functions from input.c
void to_txt(char *s,char *d);
char* read_f(char *fname);

// functions from logic.c
void clean_str(char *s, char *d);
float compare_txt(char *t1, char *t2);
int is_key(char *w);
void rem_key(char *s, char *d);
void code_sim(char *s1, char *s2);
void rem_cmt(char *s, char *d);

#endif