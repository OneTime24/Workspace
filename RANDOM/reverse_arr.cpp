/*Write a program
that copies the
elements of an
array to another in
the reverse order. */

#include <stdio.h>
int main(){
	int arr[5],arr2[5];
	for(int i=0;i<5;i++)
	{
		printf("Enter value to store: ");
		scanf(" %d",&arr[i]);
	}
	
	for(int i=0;i<5;i++){
			arr2[i]=arr[4-i];
	}
	
	for(int i=0;i<5;i++){
		printf("%d ",arr2[i]);
	}
	
}
