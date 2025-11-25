#include <stdio.h>
int main(){
	
	int n,nts=1,ntsp=1;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		for(int k=n;k>i;k--){
			printf(" ");	
	}
		for(int j=1;j<=(2*i-1);j++){
			printf("%d",j);
		}
		printf("\n");
	}
	
	
	for(int i=n-1;i>=1;i--){
		for(int k=n;k>i;k--){
			printf(" ");
		}
		for(int j=1;j<=(2*i-1);j++){
			printf("%d",j);
		}
		printf("\n");
	}
	
	
}
