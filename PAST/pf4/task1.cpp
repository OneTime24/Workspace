
/*Task-1
Create a calculator asking for operator (+ or – or * or /) and 2 operands and
perform calculation according to the user input using switch statement. */

#include <stdio.h>
int main(){
	
	printf("NAME: Mohsin Ali \nRoll Number: 25P-0545");
	printf("________________________________________________\n");
	float num1,num2;
	char ch;
	printf("Enter Operation to be perfomered (+ - * /): ");
	scanf(" %c",&ch);

	
	switch(ch){
		case '+':
			printf("Enter Number 1: ");
			scanf("%f",&num1);
			printf("Enter Number 2: ");
			scanf("%f",&num2);
			printf("%f + %f = %.3f",num1,num2,num1+num2);
			break;
		case '-':
		printf("Enter Number 1: ");
		scanf("%f",&num1);
		printf("Enter Number 2: ");
		scanf("%f",&num2);
			printf("%f - %f = %.3f",num1,num2,num1-num2);
			break;
		case '*':
			printf("Enter Number 1: ");
			scanf("%f",&num1);
			printf("Enter Number 2: ");
			scanf("%f",&num2);
			printf("%f * %f = %.3f",num1,num2,num1*num2);
			break;
		case '/':
			printf("Enter Number 1: ");
			scanf("%f",&num1);
			printf("Enter Number 2: ");
			scanf("%f",&num2);
			printf("%f / %f = %.3f",num1,num2,num1/num2);
			break;
		default:
			printf("Invalid Operation: ");
	}
	
	
}
