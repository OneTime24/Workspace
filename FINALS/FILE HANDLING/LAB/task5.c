// //Write C Program that Reads a Text File and Counts the Number of Times a Certain Letter Appears
// in the Text File
//Name: Mohsin Ali
//Roll Number: 25P-0545
#include <stdio.h>
int main(){

    FILE *ptr=fopen("task5.txt","r");

    if(ptr==NULL){
        printf("Error Opneing the file: ");
        return 0;
    }
    char x;
    printf("Enter Character to look for: ");
    scanf(" %c",&x);
    
    char ch;

    int count=0;
    while((ch=fgetc(ptr))!=EOF){

        if(ch==x){
            count++;
        }
    }

    fclose(ptr);

    printf("Character %c found %d number of times: ",x,count);
}