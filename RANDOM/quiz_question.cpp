#include <stdio.h>
int main(){
	
	int cit1[7][1],cit2[7][1];
	
	for(int i=0;i<7;i++){
		printf("Enter Temperature for City A: ");
		scanf("%d",&cit1[i][0]);
		printf("Enter Temperature for City B: ");
		scanf("%d",&cit2[i][0]);
	}
//	for(int i=0;i<7;i++){
//		
//	}
//	
	int temp[7][2];
		//city a in temp 0th colomn
		for(int i=0;i<7;i++){
			temp[i][0]=cit1[i][0];
		}
	
	
		//city B in temp 1th colomn
		for(int i=0;i<7;i++){
			temp[i][1]=cit2[i][0];
		}
	
	
	for(int i=0;i<7;i++){
		for(int j=0;j<2;j++){
			printf("%d\t",temp[i][j]);
		}
		printf("\n");
	}
	float avg=0,avg2=0,tot_avg=0;
		for(int i=0;i<7;i++){
			avg+=temp[i][0];
			avg2+=temp[i][1];
		}
	printf("\nCity A Average Temperature: %.2f",(avg)/7.0);
	printf("\nCity B Average Temperature: %.2f",(avg2)/7.0);
	tot_avg=avg+avg2;
	printf("\nOverall Average Temperature: %.2f",(tot_avg)/14.0);
	float d_avg=0;
	for(int i=0;i<7;i++){
		d_avg=temp[i][0]+temp[i][1];
		
		printf("\nDaily Average Temperature Between Two Cities: %.2f",(d_avg)/2);
	}
	
}
