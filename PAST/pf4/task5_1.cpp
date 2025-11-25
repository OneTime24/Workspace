/* Task-5
Write a program to control a coffee machine. Allow the user to input the type of coffee as B for Black
and W for White. Ask the user if the cup size is double and if the coffee is manual. The following table
details the time chart for the machine for each coffee type. Display a statement for each step. If the
coffee size is double, increase the baking time by 50 percent.*/


#include <stdio.h>
int main(){
	printf("Name: Mohsin Ali\nRoll Number: 25P-0545\n");
	printf("__________________________________________\n");
	char type,size;
	float timeW,timeB,timeW_f1,timeW_f2;
	printf("Enter Coffee Type:(b for black : w for white): ");
	scanf("%c",&type);
	printf("Enter Cup Size: (d for double : m for manual): ");
	scanf(" %c",&size);
	
	switch(type){
		case 'w':
			timeW=15+15+20+2+4+20;
			switch(size){
				case 'd':
				 	printf("Step 1: Put Water (15mins)\n");
                    printf("Step 2: Add Sugar (15mins)\n");
                    printf("Step 3: Mix Well (20mins)\n");
                    printf("Step 4: Add Coffee (2mins)\n");
                    printf("Step 5: Add Milk (4mins)\n");
                    printf("Step 6: Mix Well (20mins)\n");
				timeW_f1=timeW*(50.0/100.0);
				timeW_f2=timeW+timeW_f1;
					printf("Total Time Taken for White Coffee with Cup Size Double: %.1f mins\n", timeW_f2);
				break;
				case 'm':
					printf("Step 1: Put Water (15 mins)\n");
		            printf("Step 2: Add Sugar (15 mins)\n");
		            printf("Step 3: Mix Well (20 mins)\n");
		            printf("Step 4: Add Coffee (2 mins)\n");
		            printf("Step 5: Add Milk (4 mins)\n");
		            printf("Step 6: Mix Well (20 mins)\n");
		            
					printf("Total Time Taken for White Coffee with Cup Size Manual: %f",timeW);
					break;
				default:
					printf("Invalid Input");
					break;
			}
			break;
		case 'b':
			timeB=20+20+25+15+25;
			switch(size){
				case 'd':
				 	printf("Step 1: Put Water (20mins)\n");
                    printf("Step 2: Add Sugar (20mins)\n");
                    printf("Step 3: Mix Well (25mins)\n");
                    printf("Step 4: Add Coffee (15 mins)\n");
                    printf("Step 5: Mix Well (25mins)\n");
				timeW_f1=timeB*(50.0/100.0);
				timeW_f2=timeB+timeW_f1;
				printf("Total Time Taken for Black Coffee with Cup Size Double: %f",timeW_f2);
				break;
				case 'm':
					printf("Step 1: Put Water (20 mins)\n");
                    printf("Step 2: Add Sugar (20 mins)\n");
                    printf("Step 3: Mix Well (25 mins)\n");
                    printf("Step 4: Add Coffee (15 mins)\n");
                    printf("Step 5: Mix Well (25 mins)\n");
					printf("Total Time Taken for Black Coffee with Cup Size Manual: %f",timeB);
					break;
				default:
					printf("Invalid Input");
		}
			
	}
	
}
