
//Mohsin Ali
//25P-0545

#include <stdio.h>
int main(){
	printf("NAME: Mohsin Ali\nRoll Number: 25P-0545\n");
	int r1,r2,fz=0,bz=0,fbz=0;
	printf("Enter Starting Number: ");
	scanf("%d",&r1);
	printf("Enter Ending Number: ");
	scanf("%d",&r2);
	
	for(int i=r1;i<=r2;i++){
		if(i%3==0){
			fz++;
		}
		if(i%5==0){
			bz++;
		}
		if(i%3==0 && i%5==0){
			fbz++;
		}
	}
	
	printf("FIZZ = %d\nBUZZ = %d\nFIZZ-BUZZ = %d",fz,bz,fbz);
	
}
