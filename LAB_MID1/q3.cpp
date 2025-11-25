// Factorial of Number: 

//#include <stdio.h>
//int main(){
//	
//	int n,fact=1;
//	printf("Enter a Number: ");
//	scanf("%d",&n);
//	
//	for(int i=n;i>=2;i--){
//		fact=fact*i;
//	}
//	printf("Factorial: %d",fact);
//	
//}

// Prime Numbers: 
#include <stdio.h>
int main(){
	int count,isprime;
	for(int i=2;i<=100;i++){
		isprime=1;
		for(int j=2;j<=i/2;j++){
			
			if(i%j==0){
				isprime=0;
				break;
			}
		}
	
	if(isprime==1){
		printf("%d ",i);
	}
		}
	}
	
	

