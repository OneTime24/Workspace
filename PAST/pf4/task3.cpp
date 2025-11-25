/*Task-3
An online shopping store is providing discounts on the items due to the Eid. If the
cost of items is more than 1999 it will give a discount upto 50%. If the cost of
shopping is 2000 to 4000, a 20% discount will be applied. If the cost of shopping is
4001 to 6000, a 30% discount will be applied. If it's more than 6000 then 50%
discount will be applied to the cost of shopping. Print the actual amount, saved
amount and the amount after discount. */

#include <stdio.h>
int main(){
	printf("NAME: Mohsin Ali \nRoll Number: 25P-0545\n");
	printf("________________________________________________\n");
	float cost,saved_am,final_p;
	int disc;
	printf("Enter Amount Spent: ");
	scanf(" %f",&cost);
	if(cost>1999 && cost<=4000){
		disc=20;
	}else if(cost>4000 && cost<=6000){
		disc=30;
	}else if(cost>6000){
		disc=50;
	}else{
		disc=0;
	}
	saved_am=cost*(disc/100.0);
	final_p=cost-saved_am;
	printf("Actual Amount (Before Discount): %f",cost);
	printf("\nFinal Amount (After Discount): %f",final_p);
	printf("\nTotal Discount: %d",disc);
	printf("\nSaved Amount: %f",saved_am);
	
}
