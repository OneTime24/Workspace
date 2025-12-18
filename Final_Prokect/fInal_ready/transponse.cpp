#include <stdio.h>
int main(){
	int m,n,n2,p;
	printf("Enter Dimensions of Array1 ");
	scanf("%d %d",&m,&n);
	int arr1[m][n];
	int arr2[n][m];
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("Enter Element: ");
			scanf("%d",&arr1[i][j]);
		}
	}
//	printf("Enter Dimensions of Array2 ");
//	scanf("%d %d",&n2,&p);
//	int arr2[n2][p];
//	
//	int arr3[m][p];

for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
		arr2[j][i]=arr1[i][j];
}
}
printf("ARRAY A\n");
for(int i=0;i<m;i++){
	for(int j=0;j<n;j++){
		printf("%d\t",arr1[i][j]);
	}
	printf("\n");
}
printf("TRANSPOSE: \n");
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		printf("%d\t",arr2[i][j]);
	}
	printf("\n");
}	
}
