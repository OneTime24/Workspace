#include <stdio.h>
int main(){
	
	int arr[5],val=0;
	for(int i=0;i<5;i++){
		
		printf("Enter Value to store: ");
		scanf("%d",&arr[i]);
		
	}
	
	printf("Enter Value to search: ");
	scanf("%d",&val);
	
	int tf=-1;
	
	for(int i=0;i<5;i++){
		if(arr[i]==val){
			tf=i;
		}
	}
	
	if(tf>=0){
		printf("%d is found at %d index: ",val,tf);
	}
	
	
}
