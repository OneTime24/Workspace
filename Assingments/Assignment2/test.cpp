#include <stdio.h>
int main(){
	
	int arr[10][10]={0};
//	for(int i=0;i<10;i++){
//		for(int j=0;j<10;j++){
//			printf("%d ",arr[i][j]);
//		}
//	printf("\n");
//	}
	
	
	for(int i=0;i<10;i++){
		arr[i][0]=1;
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			printf("%d ",arr[i][j]);
		}
	printf("\n");
	}
	printf("\n");
	for(int i=0;i<10;i++){
		arr[i][i]=1;
	}
		for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			printf("%d ",arr[i][j]);
		}
	printf("\n");
	}
	for(int i=0;i<10;i++){
		arr[i][9]=1;
	}
	printf("\n");
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			printf("%d ",arr[i][j]);
		}
	printf("\n");
	}
	
	
	for(int i=0;i<10;i++){
		arr[i][10-1-i]=1;
		
	}
		printf("\n");
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			printf("%d ",arr[i][j]);
		}
	printf("\n");
	}
}
