// //Write a C program to create 2 text files and store some text inside them. Then read these 2 files into
// the program and merge the text into a 3rd text file.
//Name: Mohsin Ali
//Roll Number: 25P-0545

#include <stdio.h>
int main(){


    FILE *ptr=fopen("task4_1.txt","w");

    fputs("Hello World. ",ptr);
    fclose(ptr);

    FILE *ptr1=fopen("task4_2.txt","w");

    fputs("My Name is Ali, I am a CS Student. ",ptr1);

    fclose(ptr1);

    FILE *ptr2=fopen("task4_f.txt","w");
    ptr1=fopen("task4_2.txt","r");
    ptr=fopen("task4_1.txt","r");


    char ch;

    while((ch=fgetc(ptr))!=EOF){
        fputc(ch,ptr2);
    }
    while((ch=fgetc(ptr1))!=EOF){
        fputc(ch,ptr2);
    }

    fclose(ptr);
    fclose(ptr2);
    fclose(ptr1);
    printf("Program Run Successfull! ");

}