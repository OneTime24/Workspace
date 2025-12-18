//Given an array of integers nums and an integer target, return indices of the two numbers such that they
//add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same
//element twice.

#include <stdio.h>
int main(){
	
	int n;
	printf("Enter size of array: ");
	scanf(" %d",&n);
	int arr[n];
	int tr;
	printf("Enter target in array: ");
	scanf(" %d",&tr);
	for(int i=0;i<n;i++){
		printf("Enter %d elemetn: ",i+1);
		scanf(" %d",&arr[i]);
	}
	
//	for(int i=0;i<n;i++){
//		for(int j=i;j<n;j++){
//			int sum=arr[i]+arr[j+1];
//			if(sum==tr){
//				printf("[%d %d]",j,j+1);
//				return 0;
//			}
//			
//		}
//	}
// for(int i=0 ; i<n ; i++)
// {
// 	int sum=arr[i]+arr[i+1];
// 	if(sum==tr)
// 	{
// 		printf("[%d %d]",i,i+1);
//			return 0;
//		}
// 		
//	 }
for(int i=0 ; i<n ; i++)
{
	for(int j=i+1 ; j<n ; j++)
	{
		int sum = arr[i]+arr[j];
		if(sum==tr)
		{
			printf("[%d %d]",i,j);
			return 0;
		}
	}
}
 }

