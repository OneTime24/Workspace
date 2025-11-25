#include <stdio.h>
int main(){
	
	int n;
	printf("Enter n: ");
	scanf("%d",&n);
	printf("*\n");	
	for(int i=2;i<n-1;i++){
		printf("*");
		
		for(int j=1;j<=(i-2);j++){
			printf(" ");
		}
		
		printf("*\n");
	}
	
	for(int i=0;i<n;i++){
		printf("*");
		
	}
	printf("\n");
}
