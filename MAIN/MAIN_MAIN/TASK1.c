//Take Two numbers from user and divide both numbers but do not use the division operator.
//Name: Mohsin Ali
//Roll Number: 25P=0545


#include <stdio.h>
#include <math.h>
int main(){
    printf("Name: Mohsin Ali\nRollNumber: 25P-0545\n_____________________________________\n");
    float a,b;
    printf("Enter Num1: ");
    scanf("%f",&a);
    printf("Enter Num2: ");
    scanf("%f",&b);

    float div=pow(b,-1);
    float fn=a*div;

    printf("dividsion of Two numbers: %.3f",fn);

    return 0;

}