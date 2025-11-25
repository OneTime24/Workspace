#include <stdio.h>
int main(){
	
	int arr[]={1,2,3,4},n,x;
	int max=arr[0];
//	printf("Enter index to append: ");
//	scanf("%d",&n);
//	for(int i=3;i>=n;i--){
//		arr[i+1]=arr[i];
//	}
//	printf("Enter Value to append: ");
//	scanf("%d",&x);
//	arr[n]=x;
	
	
	for(int i=0;i<4;i++){
		if(arr[i]<i){
		
			max=arr[i];
		}
		}
	
	for(int i=0;i<4;i++){
		printf("%d ",arr[i]);
	}
	
	printf("\nMax Number: %d",max);
	
	
	
}
