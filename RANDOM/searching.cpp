#include <stdio.h>
int main(){
	int arr[2][2];
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			printf("Enter elements: ");
			scanf("%d",&arr[i][j]);
		}
	}
	int max=0;
	
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			if(arr[i][j]<max){
				max=arr[i][j];
				
			}
		}
		
	}
		printf("%d max",max);
}
