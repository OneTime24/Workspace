#include <stdio.h>
int main(){
	int x,y,z;
	printf("ENTER three Numbers: ");
	scanf("%d %d %d",&x,&y,&z);
	if((x>y)&&(x>z))
		printf("%d x is greatest ",x);
	else if((y>z)&&(y>x))
		printf("%d y is greatest ",y);
	else if((z>x)&&(z>y))
		printf("%d z is greatest ",z);
	else{
		printf("Invalid Input");
	}
}	
