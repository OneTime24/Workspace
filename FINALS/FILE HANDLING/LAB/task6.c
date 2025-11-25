// Consider a String entered by the user which he wants to encrypt and then decrypt the information.
// Perform this functionality via the filling technique by first inserting the encrypted text in the file
// then read the encrypted text to decode it back to string.
//Name: Mohsin Ali
//Roll Number: 25P-0545
#include <stdio.h>
#include <string.h>
int main(){

    char word[256];

    printf("Enter Word: ");

    fgets(word,256,stdin);

    word[strcspn(word, "\n")] = '\0';

    int ln=strlen(word);

    for(int i=0;word[i]!='\0';i++){
        word[i]+=i+1;
    }
    printf("\nEncrypted text: \n");
    for(int i=0;i<ln;i++){
        printf("%c",word[i]);
    }

    FILE *ptr=fopen("task6.txt","w");

    fputs(word,ptr);

    fclose(ptr);

    ptr=fopen("task6.txt","r");

    for(int i=0;word[i]!='\0';i++){

        word[i]-=(i+1);

    }
    printf("\nDecrypted Text: \n");

    printf("%s",word);
}