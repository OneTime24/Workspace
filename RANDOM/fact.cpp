#include <stdio.h>
int main(){
	while(1){
	int n,fact=1;
	printf("Enter a number: ");
	scanf("%d",&n);
	
	for(int i=n;i>=1;i--){
		fact*=i;
	}
	printf("Factorial of %d is: %d",n,fact);
	printf("\nDo you want to find factorial of another number?? (Y for Yes / N for No): ");
	char ch;
	scanf(" %c",&ch);
	if(ch=='y'||ch=='Y'){
		continue;
	}else{
		break;
	}
}
	
}
