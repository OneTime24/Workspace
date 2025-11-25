/*Task-6
Using IF and Switch statement, write a program that displays the following menu for the food items
available to take order from the customer:
· B= Burger (Rs. 200)
· F= French Fries (Rs. 50)
· P= Pizza (Rs. 500)
· S= Sandwiches (Rs. 150)
The costumer can order any combination of available food. The program first ask to enter the no of
types of snacks i.e. 2, 3 or 4 then it ask to enter the choice i.e. B for Burger and then for quantity. The
program should finally display the total charges for the order. */

#include <stdio.h>
int main(){
	printf("Name: Mohsin Ali\nRoll Number: 25P-0545\n");
	char ch,ch2,ch3,ch4;
	int q,buy,buy2,buy3,buy4,total=0;
	printf("\t\t\t\t\tABC RESTAURENT\t\t\t\t\t\n");
	printf("\t\t\t\t\t  WELCOME!!\n");
	printf(" MENU:: \n\n");
	printf(". B= Burgers (RS: 200)\n. F= French Fries (RS: 50)\n. P= Pizza (RS:500)\n. S= Sandwiches (RS:150)\n");
	printf("Enter Number of Snacks You Want to you: ");
	scanf("%d",&q);
	
	switch(q){
		case 1:
		printf("Enter First Snack to order: ");
		scanf(" %c",&ch);
		printf("Enter Quantity: \n");
		scanf("%d",&buy);
		printf("\nYou Have Ordered: \n");
			if(ch=='B'){
				total+=buy*200;
				printf("%d Burgers value %d\n",buy,buy*50);
			}else if(ch=='F'){
				total+=buy*50;
				printf("%d Fries value %d\n",buy,buy*50);
			}else if(ch=='P'){
				total+=buy*500;
				printf("%d Pizza value %d\n",buy,buy*500);
			}else if(ch=='S'){
				total+=buy*150;
				printf("%d Sandwiches value %d\n",buy,buy*150);
				}else{
				
				printf("Invalid Choice: ");
			}
			break;
		case 2:
			printf("Enter First Snack to order: ");
			scanf(" %c",&ch);
			printf("Enter Quantity: \n");
			scanf(" %d",&buy);
			printf("Enter Second Snack to order: ");
			scanf(" %c",&ch2);
			printf("Enter Quantity: \n");
			scanf(" %d",&buy2);
			printf("\nYou Have Ordered: \n");
			if(ch=='B'){
				total+=buy*200;
				printf("%d Burgers value %d\n",buy,buy*200);
			}else if(ch=='F'){
				total+=buy*50;
				printf("%d Fries value %d\n",buy,buy*50);
			}else if(ch=='P'){
				total+=buy*500;
				printf("%d Pizza value %d\n",buy,buy*500);
			}else if(ch=='S'){
				total+=buy*150;
				printf("%d Sandwiches value %d\n",buy,buy*150);
			}	
		if(ch2=='B'){
				total+=buy2*200;
				printf("%d Burgers value %d\n",buy2,buy2*200);
			}else if(ch2=='F'){
				total+=buy2*50;
				printf("%d Fries value %d\n",buy2,buy2*50);
			}else if(ch2=='P'){
				total+=buy2*500;
				printf("%d Pizza value %d\n",buy2,buy2*500);
			}else if(ch2=='S'){
				total+=buy2*150;
				printf("%d Sandwiches value %d\n",buy2,buy2*150);
		}else{
			printf("Invalid CHOICE: ");
		}
			break;
				
		case 3:
			printf("Enter First Snack to order: ");
			scanf(" %c",&ch);
			printf("Enter Quantity: \n");
			scanf(" %d",&buy);
			printf("Enter Second Snack to order: ");
			scanf(" %c",&ch2);
			printf("Enter Quantity: \n");
			scanf(" %d",&buy2);
			printf("Enter Third Snack to Order: ");
			scanf(" %c",&ch3);
			printf("Enter Quantity: \n");
			scanf(" %d",&buy3);
			printf("\nYou Have Ordered: \n");
			if(ch=='B'){
				total+=buy*200;
				printf("%d Burgers value %d\n",buy,buy*200);
			}else if(ch=='F'){
				total+=buy*50;
				printf("%d Fries value %d\n",buy,buy*50);
			}else if(ch=='P'){
				total+=buy*500;
				printf("%d Pizza value %d\n",buy,buy*500);
			}else if(ch=='S'){
				total+=buy*150;
				printf("%d Sandwiches value %d\n",buy,buy*150);
			}	
		if(ch2=='B'){
				total+=buy2*200;
				printf("%d Burgers value %d\n",buy2,buy2*200);
			}else if(ch2=='F'){
				total+=buy2*50;
				printf("%d Fries value %d\n",buy2,buy2*50);
			}else if(ch2=='P'){
				total+=buy2*500;
				printf("%d Pizza value %d\n",buy2,buy2*500);
			}else if(ch2=='S'){
				total+=buy2*150;
				printf("%d Sandwiches value %d\n",buy2,buy2*150);
		}
		if(ch3=='B'){
				total+=buy3*200;
				printf("%d Burgers value %d\n",buy3,buy3*200);
			}else if(ch3=='F'){
				total+=buy3*50;
				printf("%d Fries value %d\n",buy3,buy3*50);
			}else if(ch3=='P'){
				total+=buy3*500;
				printf("%d Pizza value %d\n",buy3,buy3*500);
			}else if(ch3=='S'){
				total+=buy3*150;
				printf("%d Sandwiches value %d\n",buy3,buy3*150);
			}else{
				printf("INVALID CHOICE: ");
			}
		case 4:
			printf("Enter First Snack to order: ");
			scanf(" %c",&ch);
			printf("Enter Quantity: \n");
			scanf(" %d",&buy);
			printf("Enter Second Snack to order: ");
			scanf(" %c",&ch2);
			printf("Enter Quantity: \n");
			scanf(" %d",&buy2);
			printf("Enter Third Snack to Order: ");
			scanf(" %c",&ch3);
			printf("Enter Quantity: \n");
			scanf(" %d",&buy3);
			printf("Enter Fourth Snack to Order: ");
			scanf(" %c",&ch4);
			printf("Enter Quantity: ");
			scanf(" %d",&buy4);
			printf("\nYou Have Ordered: \n");
			if(ch=='B'){
				total+=buy*200;
				printf("%d Burgers value %d\n",buy,buy*200);
			}else if(ch=='F'){
				total+=buy*50;
				printf("%d Fries value %d\n",buy,buy*50);
			}else if(ch=='P'){
				total+=buy*500;
				printf("%d Pizza value %d\n",buy,buy*500);
			}else if(ch=='S'){
				total+=buy*150;
				printf("%d Sandwiches value %d\n",buy,buy*150);
			}	
		if(ch2=='B'){
				total+=buy2*200;
				printf("%d Burgers value %d\n",buy2,buy2*200);
			}else if(ch2=='F'){
				total+=buy2*50;
				printf("%d Fries value %d\n",buy2,buy2*50);
			}else if(ch2=='P'){
				total+=buy2*500;
				printf("%d Pizza value %d\n",buy2,buy2*500);
			}else if(ch2=='S'){
				total+=buy2*150;
				printf("%d Sandwiches value %d\n",buy2,buy2*150);
		}
		if(ch3=='B'){
				total+=buy3*200;
				printf("%d Burgers value %d\n",buy3,buy3*200);
			}else if(ch3=='F'){
				total+=buy3*50;
				printf("\n%d Fries value %d\n",buy3,buy3*50);
			}else if(ch3=='P'){
				total+=buy3*500;
				printf("\n%d Pizza value %d\n",buy3,buy3*500);
			}else if(ch3=='S'){
				total+=buy3*150;
				printf("\n%d Sandwiches value %d\n",buy3,buy3*150);
		}
		if(ch4=='B'){
				total+=buy4*200;
				printf("\n%d Burgers value %d\n",buy4,buy4*200);
			}else if(ch4=='F'){
				total+=buy4*50;
				printf("\n%d Fries value %d\n",buy4,buy4*50);
			}else if(ch4=='P'){
				total+=buy4*500;
				printf("\n%d Pizza value %d\n",buy4,buy4*500);
			}else if(ch4=='S'){
				total+=buy4*150;
				printf("\n%d Sandwiches value %d\n",buy4,buy4*150);
		}else{
			printf("\nInvalid Input");
		}
}
printf("\nTotal Price: %d",total);
}
