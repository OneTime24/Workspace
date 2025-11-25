#include <stdio.h>
int main(){
	
	int arr1[7][2];
	int arr2[7][2];
	printf("For City A");
	for(int i=0;i<7;i++){
		for(int j=0;j<2;j++){
			printf("Enter element: ");
			scanf("%d",&arr1[i][j]);
		}
	}
	printf("For City B");
	for(int i=0;i<7;i++){
		for(int j=0;j<2;j++){
			printf("Enter element: ");
			scanf("%d",&arr2[i][j]);
		}
	}
	
	float avg1,avg2;
	
	for(int i=0;i<7;i++){
		for(int j=0;j<2;j++){
			avg1+=arr1[i][j];
			avg2+=arr2[i][j];
		}
	}
	printf("Average of City A: %f",avg1/14.0);
	printf("Average of City B: %f",avg2/14.0);
	
	printf("Overall Average: %f",(avg1+avg2)/28);
	
	for(int i=0;i<7;i++){
		for(int j=0;j<2;j++){
			printf("daily average of day %d",i);
			printf("%d",(arr1[i][j]+arr2[i][j])/2);
		}
	}
	
	
	
	
	
}
