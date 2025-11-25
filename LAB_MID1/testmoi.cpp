#include <stdio.h>
int main(){
	
	int a=0,b=1,sum,n,final=0;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		sum=a+b;
		printf("%d ",b);
		a=b;
		b=sum;
		final+=sum;
	}
	printf("\n%d",final);
	
	
}
