#include <stdio.h>
int main(){
	
	float a = 10.5;
	int b=5;
	int c=2;
	int d=8;
	int e=3;
	
	int result1=a*=a+b*c%d;
	float result2=(a+b)*c;
	int result3=d%b+e-a*a;
	printf("Result is: %d",result1);
	printf("\n%.3f",result2);
	printf("\nResult is%10d",result3);

}
