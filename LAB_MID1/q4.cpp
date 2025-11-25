//FIBBONACCI SERIES:

//#include <stdio.h>
//int main(){
//	
//	int n,a=0,b=1,fab=1;
//	printf("Enter Number: ");
//	scanf("%d",&n);
//	
//	for(int i=1;i<=n;i++){
//		fab=a+b;
//		printf("%d ",b);
//		a=b;
//		b=fab;
//	}
//	
//}

//Reverse an input;

#include <stdio.h>
int main(){
	
	int n,rev=0,remainder;
	printf("Enter a Number: ");
	scanf("%d",&n);
	
	while(n!=0){
		remainder=n%10;
		rev=rev*10+remainder;
		n=n/10;
	}
	printf("REVERSED: %d",rev);
	
}
