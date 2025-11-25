#include<stdio.h>
int main(){
	
	int arr[5][10]={0};
	
	for(int i=0;i<5;i++){
		printf("For %d student: \n",i+1);
		for(int j=0;j<10;j++){
			printf("Marks of %d Subject: ",j+1);
			scanf("%d",arr[i][j]);
		}
	}
	
	printf("\n");
	
	for(int i=0;i<5;i++){
		printf("Student %d",i+1);
		for(int j=0;j<10;j++){
			printf("%d for course %d",arr[i][j],j+1);
		}
		printf("\n");
	}
	
	
}
