// Write a program that checks whether a string entered by the
// user is a palindrome or not.
// Palindrome is a word that remains same even if it is reversed
// Write two versions:
// Without using string functions
// Using string functions
//1. NOT USING STRING FUNCTION: 
#include <stdio.h>
#include <string.h>
int main(){

    char name[256];
    char rev[256];
    printf("Enter a wrod: ");
    scanf("%[^\n]",name);
    // fgets(name,sizeof(name),stdin);
    int ln=strlen(name);
    printf("%d\n",ln);
    
    for(int i=0;i<ln;i++){
        rev[i]=name[ln-1-i];
    }
    rev[ln]='\0';
    
    printf("Name: %s\n",name);
    printf("Reversed: %s\n",rev);
    int flg=1; // initially palindrome
    for(int i=0;i<ln;i++){
        if(rev[i]!=name[i]){
            flg=0;
            break;
        }
    }
    if(flg==1){
        printf("\nPALINDROME: ");
    }else{
        printf("NOT PALINDROME: ");
    }


}


//2. Using String Functions:

#include <stdio.h>
#include <string.h>
int main(){

    char name[100];
    char name2[100];
    printf("Enter Word: ");
    scanf("%[^\n]",name);
    printf("Word: %s\n",name);
    strcpy(name2,name);
    strrev(name2);
    printf("Reversed: %s\n",name2);
    if(strcmp(name2,name)==0){
        printf("Palindrome: ");
    }else{
        printf("Not Palindrome: ");
    }

}