// Write a program that asks the user to enter his full name
// having three parts: first name, middle name and last name. It
// then prints his name in the following order

// Last name, First Name Middle Name

// Example: Usman Ali Shah 🡪 Shah, Usman Ali

// Two versions:

// Using strtok()

// Without using strtok()

#include <stdio.h>
#include <string.h>
int main(){

    printf("Please Enter your Full Name: ");
    char name[256];
    char *first, *second, *third;

    fgets(name,sizeof(name),stdin);
    name[strcspn(name,"\n")]='\0';

    first=strtok(name," ");
    second=strtok(NULL," ");
    third=strtok(NULL," ");

    printf("%s %s %s",third,second,first);




}