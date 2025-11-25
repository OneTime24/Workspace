/* Q5. Write a C program using if-else and switch-case:- 
Take a number from the user.- If the number is positive, 
check if it is also greater than 100 ? print "Big Positive" or "Small
 Positive".- If the number is negative, use switch-case
  on (number % 2) to print whether it is "Negative Even"
 or "Negative Odd".- If the number is zero, print "Neutral" 
 */

#include <stdio.h>
int main(){
	
	int x,mod;
	scanf("%d",&x);
	
	if(x>0){
		
		if(x>100){
			printf("Big Positive");
		}else{
			printf("Small Positive");
			
		}
		
	}else if(x<0){
		mod=x%2;
		switch(mod){
			case 0:
				printf("Negative EVEN");
				break;
			default:
				printf("Negative ODD");
		}
	}else if(x==0){
		printf("NEUTRAL");
	}else{
		printf("INVALID INPUT");
	}
	
	
}
