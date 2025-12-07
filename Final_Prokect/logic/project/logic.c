#include "logic.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

FILE *report_file = NULL;

int isKeyword(char *word) {
    char *keywords[] = {"int","float","double","char","void","if","else","while","for","return"};
    for (int i=0;i<10;i++){
        if(strcmp(word,keywords[i])==0)
            return 1;
    }
    return 0;
}

void removeCommentsAndHeaders(char *src, char *dest) {
    int i=0,j=0;
    while(src[i]!='\0'){
        if(src[i]=='#'){ while(src[i]!='\n' && src[i]!='\0') i++; continue; }
        if(src[i]=='/' && src[i+1]=='/'){ i+=2; while(src[i]!='\n' && src[i]!='\0') i++; continue; }
        if(src[i]=='/' && src[i+1]=='*'){ i+=2; while(!(src[i]=='*' && src[i+1]=='/') && src[i]!='\0') i++; if(src[i]!='\0') i+=2; continue; }
        dest[j++]=src[i++];
    }
    dest[j]='\0';
}

void removeKeywords(char *src, char *dest) {
    int i=0,j=0,w=0;
    char word[50];
    while(src[i]!='\0'){
        if(isalpha(src[i])) word[w++]=src[i];
        else {
            word[w]='\0';
            if(w>0 && !isKeyword(word)){
                for(int x=0;word[x]!='\0';x++) dest[j++]=word[x];
            }
            w=0;
            dest[j++]=src[i];
        }
        i++;
    }
    dest[j]='\0';
}

float checkPlgText(char *txt1,char *txt2){
    char *c1=malloc(strlen(txt1)+1),*c2=malloc(strlen(txt2)+1);
    strcpy(c1,txt1); strcpy(c2,txt2);

    char *t1[1000],*t2[1000];
    int n1=0,n2=0;
    char *p=strtok(c1," ");
    while(p){ 
        t1[n1]=malloc(strlen(p)+1); 
        strcpy(t1[n1++],p); 
        p=strtok(NULL," "); 
    }

    p=strtok(c2," ");
    while(p){ t2[n2]=malloc(strlen(p)+1); strcpy(t2[n2++],p); p=strtok(NULL," "); }

    free(c1); free(c2);

    int match=0;
    for(int i=0;i<n1-2;i++){
        for(int j=0;j<n2-2;j++){
            if(strcmp(t1[i],t2[j])==0 && strcmp(t1[i+1],t2[j+1])==0 && strcmp(t1[i+2],t2[j+2])==0){
                match++;
                if(report_file) fprintf(report_file,"  - \"%s %s %s\"\n",t1[i],t1[i+1],t1[i+2]);
                break;
            }
        }
    }
    float sim = ( (float)match / (n1-2) ) * 100;
    for(int i=0;i<n1;i++) free(t1[i]);
    for(int i=0;i<n2;i++) free(t2[i]);
    return sim;
}

void sim_chek(char *s1,char *s2){
    char *c1=malloc(strlen(s1)+1), *c2=malloc(strlen(s2)+1);
    strcpy(c1,s1); strcpy(c2,s2);
    char *t1[1000], *t2[1000];
    int n1=0,n2=0;

    char *p=strtok(c1," \n\t");
    while(p){ t1[n1]=malloc(strlen(p)+1); strcpy(t1[n1++],p); p=strtok(NULL," \n\t"); }
    p=strtok(c2," \n\t");
    while(p){ t2[n2]=malloc(strlen(p)+1); strcpy(t2[n2++],p); p=strtok(NULL," \n\t"); }

    free(c1); free(c2);

    int *used=calloc(n2,sizeof(int));
    int match=0;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(!used[j] && strcmp(t1[i],t2[j])==0){
                printf("Matched: %s\n",t1[i]);
                if(report_file) fprintf(report_file,"  - %s\n",t1[i]);
                used[j]=1; match++; break;
            }
        }
    }
    float perc=(match/(float)n1)*100;
    printf("\nTOTAL MATCHED: %d\nSIMILARITY: %.2f%%\n",match,perc);
    if(report_file){
        fprintf(report_file,"\nTotal Matches: %d\nSimilarity: %.2f%%\n",match,perc);
        fprintf(report_file,"========================================\n\n");
    }
    for(int i=0;i<n1;i++) free(t1[i]);
    for(int i=0;i<n2;i++) free(t2[i]);
    free(used);

    
}