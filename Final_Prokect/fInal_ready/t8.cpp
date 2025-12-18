/* Write a program that prints all the elements of an array
from the end to a value supplied by the user

Find the index of the value first

Then print from the end to the index found earlier */

#include <stdio.h>
int main(){
	int n,ind=-1;
	int arr[5]={1,2,3,4,5};
	printf("Enter number to find all the numbers ahead of it: ");
	scanf("%d",&n);
	
	for(int i=0;i<5;i++){
		if(arr[i]==n){
			ind=i;
		}
	}
	
	if(ind>=0){
		for(int i=4;i>=ind;i--){
			printf("%d ",arr[i]);
		}
	}else{
		printf("Value not Found: ");
	}
	
	
	
}
