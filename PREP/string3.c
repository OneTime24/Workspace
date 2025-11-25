// Write a program that converts a string into a float

// i.e., constructs a single float value from the characters stored in a
// string

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){

    char name[]="3.1456";
    float f;
    f=atof(name);
    printf("%f\n",f);
    printf("%f",f+1);
}