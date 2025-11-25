/*Write a program that
prints the square
roots of numbers
entered by the user
till a negative number
is entered. */

#include <stdio.h>
#include <math.h>
int main(){
	float n;
	
	while(1){
		printf("Enter a number to find square root: ");
		scanf(" %f",&n);
		if(n<0){
		printf("Invalid Input: Can't find square root of negative numbers: ");
		return 0;}
		printf("\nSqrt of %f: %f\n",n,sqrt(n));
	}
}
	

