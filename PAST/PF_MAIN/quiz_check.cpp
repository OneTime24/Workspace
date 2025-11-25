#include <stdio.h>
int main()
{
	int x,temp1,temp2,dig,temp3,x2;
	printf("Enter Three Digit Number: ");
	scanf("%d",&dig);
	
	x=dig/10;
	temp1=dig%10;
	
	x2=x/10;
	temp2=x%10;
	
	temp3=x2;
	
	if(temp1 && temp2 && temp3){
		if(temp3<5){
			printf("%d",temp2+temp3);
		}else{
			printf("%d",temp2*temp3);
		}
	}else{
		printf("Error");
	}
	
}
