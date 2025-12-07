#include <stdio.h>
int main(){
	
	int a=10;
	int *ptr1=&a;
	printf("%d",ptr1);
	int *ptr2=&ptr1;
	printf("\n%d",*(ptr2));
	
	
}
