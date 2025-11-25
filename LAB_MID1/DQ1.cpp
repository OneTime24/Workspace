#include <stdio.h>
#include <math.h>

int main(){
	
	int x,n,i=1,j=0,sign=1;
	float sum=0,temp=0;
	printf("Enter Number of Terms: ");
	scanf("%d",&n);
	printf("Enter Value of X: ");
	scanf("%d",&x);
	

	while(i<=n){
		temp=sign*(pow(x,j)/pow(3,i));
		sum+=temp;
		i++;
		j+=2;
		sign*=-1;
	}
	
	printf("SUM = %f",sum);
}
