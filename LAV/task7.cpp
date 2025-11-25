// Mohsin Ali
//25P-0545

#include <stdio.h>
int main(){
	
	int size,sum=0;
	printf("Enter Array Size: ");
	scanf("%d",&size);
	int arr[size];
	
	for(int i=0;i<size;i++){
		printf("Enter Value: ");
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	printf("SUM: %d",sum);
	
}
