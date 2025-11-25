/* Task-7
Mortgage Calculator) Develop a C program to calculate the interest accrued on a bank customer&#39;s
mortgage. For each customer, the following facts are available: 
a) the account number
b) the mortgage amount 
c) the mortgage term
d) the interest rate
The program should input each fact, calculate the
total interest payable (= mortgage amount × interest rate × mortgage term), and add it to the
mortgage amount to get the total amount payable. It should calculate the required monthly payment by
dividing the total amount payable by the number of months in the mortgage term. The program should
display the required monthly payment rounded off to the nearest dollar. The program should process each
customer&#39;s account at a time */

#include <stdio.h>
#include <math.h>
int main(){
	printf("Name: Mohsin Ali \nRoll Number: 25P-0545\n");
	printf("______________________________________________\n");
	
	float total_in,rate;
	int mort_am,mort_term,acc,total_pm,mort_term_m;
	printf("Enter Account Number: (-1 to end): ");
	scanf("%d",&acc);
	switch(acc){
		case -1:
			printf("Good Bye: ");
			break;
		default:
			printf("Mortgage Amount:(in dollars): ");
			scanf("%d",&mort_am);
			printf("Mortgage Term: (in years): ");
			scanf("%d",&mort_term);
			printf("Enter Interest Rate: (in decimal): ");
			scanf("%f",&rate);
			total_in=mort_am*rate*mort_term;
			mort_am+=total_in;
			
			mort_term_m=mort_term*12;
			
			total_pm=round((float)mort_am/mort_term_m);
			
			printf("The monthly Payable Interest $: %d",total_pm);
			
			return 0;
	}
	
}
