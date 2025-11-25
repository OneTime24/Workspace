/* Write a program that first asks the user to enter the
dimensions of matrices. It then asks the user to supply
values for matrices A and B. It then calculates the matrix
C = A + B. Finally, it prints out all the matrices A, B and
C. */

#include <stdio.h>
int main(){
	int m,n;
	
	printf("Enter Dimension of array: ");
	scanf("%d",&m);
	scanf("%d",&n);
	int arr1[m][n],arr2[m][n],arr3[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("Enter element for array 1: ");
			scanf("%d",&arr1[i][j]);
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("Enter element for array 2: ");
			scanf("%d",&arr2[i][j]);
		}
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			arr3[i][j]=arr1[i][j]+arr2[i][j];
		}
	}
	printf("Matrix A\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",arr1[i][j]);
		}
		printf("\n");
	}
	printf("Matrix B\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",arr2[i][j]);
		}
		printf("\n");
		
	}
	printf("Matrix C\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",arr3[i][j]);
		}
		printf("\n");
	}
	
		
}
