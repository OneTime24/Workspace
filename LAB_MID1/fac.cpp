#include<stdio.h>
int main(){
		
	int fac,final=1;
	scanf("%d",&fac);
	
	for(int i=1;i<=fac;i++){
		final*=i;
	}

	printf("%d",final);
	
}
