//Mohsin Ali
//25P-0545

#include <stdio.h>
int main(){
	printf("NAME: Mohsin Ali\nRoll Number: 25P-0545\n");
	int n1,n2,temp,gcd,lcm;
	int x,y;
	printf("Enter Num1: ");
	scanf("%d",&n1);
	printf("Enter Num2: ");
	scanf("%d",&n2);

	x=n1,y=n2;
	while(n2!=0){
		temp=n2;
		n2=n1%n2;
		n1=temp;
	}
	gcd=n1;
	lcm=(x*y)/gcd;
	
	printf("LCM = %d\nGCD = %d",lcm,gcd);
	
	

}
