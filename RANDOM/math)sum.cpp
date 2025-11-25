#include <stdio.h>
int main(){
	
	float sum=0;
	
	for(int i=1;i<=5;i++){
		sum+=(float)i/(i+5);
	}
	printf("Sum = %f",sum);
	
	
}
