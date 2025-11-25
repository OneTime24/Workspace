/*Write a program that asks the user to enter two numbers,
say n1, n2. The program then prints Prime / Not Prime
for all the numbers starting from n1 and ending at n2.  */


#include <stdio.h>
int main(){
	
	int i,j,x,y,flag;
	printf("Enter x: ");
	scanf("%d",&x);
	printf("Enter y: ");
	scanf("%d",&y);
	
	for(i=x;i<=y;i++){
		for(j=2;j<i;j++){
			if(i%j==0){
				printf("%d Not Prime: ",i);
				break;
			}
			
			
		}
		if(i==j){
			printf("%d Prime: ",i);
		}
	}
	
	
	}
	
	
	

