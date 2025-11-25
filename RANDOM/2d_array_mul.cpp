/*• Write a program that first asks the user to enter the
dimension of matrices. It then asks the user to supply
values for matrices A and B. It then calculates the matrix
C = A x B. Finally, it prints out all the matrices A, B and
c. */

#include <stdio.h>
int main(){
	int m,n,n2,p;
	printf("Enter Dimensions of Array1 ");
	scanf("%d %d",&m,&n);
	int arr1[m][n];
	printf("Enter Dimensions of Array2 ");
	scanf("%d %d",&n2,&p);
	int arr2[n2][p];
	
	int arr3[m][p];
	if(n==n2){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("Enter Element of array 1: ");
			scanf("%d",&arr1[i][j]);
		}
	}
	
	for(int i=0;i<n2;i++){
		for(int j=0;j<p;j++){
			printf("Enter Element of array 2: ");
			scanf("%d",&arr2[i][j]);
		}
	}
	
	
	for(int i=0;i<m;i++){
		for(int j=0;j<p;j++){
			arr3[i][j]=0;
			
			for(int k=0;k<n;k++){
				arr3[i][j]+=arr1[i][k]*arr2[k][j];
			}
			
		}
	}
	
	printf("Array C: \n");
	for(int i=0;i<m;i++){
		for(int j=0;j<p;j++){
			printf("%d ",arr3[i][j]);
		}
		printf("\n");
	}
	}else{
		printf("Can not Multiply them: ");
		return 0;
	}
	
	
	
}
