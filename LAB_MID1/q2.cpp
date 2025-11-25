// 14.Create a program to classify a number as a perfect number.

#include <stdio.h>
int main(){
	
	int num,sum=0;
	
	printf("Enter Number: ");
	scanf("%d",&num);
	
	for(int i=1;i<1num;i++){
		
		if(num%i==0){
			sum+=i;
		}
		
		
	}
	
	if(num==sum){
		printf("Number is Perfect Number: %d",num);
	}else{
		printf("Number is Not Perfect Number: %d",num);
	}
	
}
