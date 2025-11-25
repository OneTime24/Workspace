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
int main(){
	
	float mort_am,mort_term,total_in;
	int acc,total_pm,rate;
	printf("Enter Account Number: ");
	scanf("%d",&acc);
	switch(acc){
		case -1:
			printf("Invalid BANK: ");
			break;
		default:
			printf("Mortage Amount: ");
			scanf("%d",&mort_am);
			printf("Mortage Term: ");
			scanf("%d",&mort_term);
			printf("Enter Interest Rate: ");
			scanf("%f",&rate);
			total_in=mort_am*rate*mort_term;
			mort_am+=total_in;
			total_pm=mort_am/mort_term;
			
			printf("The monthly Payable Interest: %d",total_pm);
			
			
	}
	
}
