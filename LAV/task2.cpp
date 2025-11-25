//Mohsin Ali
//25P-0545

#include <stdio.h>
int main(){
	printf("NAME: Mohsin Ali\nRoll Number: 25P-0545\n");
	int a=0,b=1,fab=1,sum=0;
	
	for(int i=1;i<=10;i++){			// after many turns it will exceed int range and then it will print garbage values
		fab=a+b;
		printf("%d ",b);
		if(b%3==0 || b%5==0 || b%7==0){
			sum+=b;
		}
		a=b;
		b=fab;
		
	}
	printf("\nSum = %d",sum);
	
	
}
