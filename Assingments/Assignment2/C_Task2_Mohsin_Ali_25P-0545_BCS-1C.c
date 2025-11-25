//Name: Mohsin Ali
//Roll Number: 25p-0545

#include <stdio.h>
int main(){

	printf("Name: Mohsin Ali\n");
	printf("Roll Number: 25P-0545\n");
	printf("_____________________________\n");
		int op,n,sl,jm;
		
		while(1){			//A continous loop to print menu again and again untill choosen 2:
				
				printf("Choose operation:\n");
				printf("1. Enter a new number and calculate slides and jumps to reach 1. \n2. Exit the program\n");
				scanf("%d",&op);
			switch(op){
			case 1:
				sl=0,jm=0;
				printf("Enter a number: ");
				scanf("%d",&n);					//Input NUmber to start the Magic Number Game
				
				if(n==1){						//If Number is already one, then choose another number: 
					printf("Can not choose 1, Choose another Number: ");
					continue;
			}else if(n>0){						//If number is positive then evaluate: 
			
				while(n!=1){					//Keep trying untill number is equal to 1
					if(n%2==0){
						n/=2;
						sl++;
					}else{
						n=(n*3)+1;
						jm++;
					}
				}
		}else{									//If Input Number is Negative
			printf("Invalid Input: Try again: ");
			continue;
		}
				printf("Slides: %d\nJumps: %d\n",sl,jm);
				continue;
			
			break;
		case 2:
			printf("Exiting the Program: BYE....");				//If Option is selected, Exit or return and terminate the program.
			return 0;
}
}
}
