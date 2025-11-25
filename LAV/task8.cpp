#include <stdio.h>
int main(){
	
	int size;
	printf("Enter Array Size: ");
	scanf("%d",&size);
	int arr[size];
	
	for(int i=0;i<size;i++){
		printf("Enter Value: ");
		scanf("%d",&arr[i]);
	}
	
	printf("\nARRAY IN REVERSE ORDER:\n");
	
	for(int j=size-1;j>=0;j--){

		printf("%d ",arr[j]);
	}
	
}
