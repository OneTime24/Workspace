// FIND GCD

#include <stdio.h>
int main(){
	
	int x,y,gcd=0;
	printf("Enter Numbers: ");
	scanf("%d %d",&x,&y);
	
	for(int i=1;i<=x && i<=y;i++){
		if(x%i==0 && y%i==0){
			gcd=i;
		}
		
	}
	printf("%d",gcd);
}
