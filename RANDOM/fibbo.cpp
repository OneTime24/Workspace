// Fibonacci series of first 10 elements: SUM and SERIES
//1,1,2,3,5,8.13......


#include <stdio.h>
int main(){
	int a=0,b=1,temp=0;
	for(int i=0;i<=10;i++){
		printf("%d ",b);
		a=b;
		b+=temp;
		temp=a;
	}
	
	
	
}
