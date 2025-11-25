//Example 2: Program to Open a File, Read from it, And Close the File

#include <stdio.h>
#include <string.h>
int main(){
    char str[256];
    FILE *ptr;

    ptr=fopen("lean2.txt","r");

    if(ptr==NULL){
        printf("FAILED TO OPEN THE FILE: ");
    }else{

        while(fgets(str,sizeof(str),ptr)!=NULL){
            printf("%s ",str);
        }
    }

    fclose(ptr);

}