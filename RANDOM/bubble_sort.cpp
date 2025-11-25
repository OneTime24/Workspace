//Bubble sorting: 

#include <stdio.h>
int main(){
	int n=5;
	int arr[5],temp;
	for(int i=0;i<n;i++){
		printf("enter an element: ");
		scanf("%d",&arr[i]);
	}
	
	for(int i=0;i<n-1;i++){
		for(int j=0;j<(n-1)-i;j++){
		if(arr[j]>arr[j+1]){
			temp=arr[j+1];
			arr[j+1]=arr[j];
			arr[j]=temp;
		}
	}
	}
	
	for(int i=0;i<5;i++){
		printf("%d ",arr[i]);
	}
	
	
}
