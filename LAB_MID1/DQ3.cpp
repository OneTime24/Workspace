#include <stdio.h>
int main(){
	
	int n,nts=1,ze;
	printf("Enter Number: ");
	scanf("%d",&n);
	for(int i=n;i>=1;i--){
		for(int k=n;k>i;k--){
			printf(" ");
	
	}
		for(int j=1;j<=(2*i-1);j++){
			ze=j%2;
			printf("%d",ze);
		}

		printf("\n");
	}
	
	for(int i=2;i<=n;i++){
		for(int k=n;k>i;k--){
			printf(" ");
		}
		for(int j=1;j<=(2*i-1);j++){
			ze=j%2;
			printf("%d",ze);
		}
		printf("\n");
	}
	
	
}
