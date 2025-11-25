// /Example 1: Program to Create a File, Write in it, And Close the File

#include <stdio.h>
#include <string.h>
int main(){

    char name[50]="Hello Mohsin!";

    FILE *ptr;

    ptr=fopen("learn1.txt","w");

    if(ptr==NULL){
        printf("FILE FAILED TO OPEN: ");
    }else{
        fputs("Welcome 25 Batch",ptr);
        fputs("\n",ptr);
        fputs(name,ptr);
        fputs("\n",ptr);
        char str[245];
        fgets(str,sizeof(str),stdin);
        fputs("\n",ptr);
        fputs(str,ptr);

    }
    fclose(ptr);


}