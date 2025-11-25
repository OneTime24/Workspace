#include <stdio.h>
int main(){
	
	int size=7;
	int temp[size]={15,25,30,33,11,23,43};
	int cold=0,mild=0,hot=0;
	
	for(int i=0;i<size;i++){
		if(temp[i]<=20)
			cold++;
		if(temp[i]>20 && temp[i]<35)
			mild++;
		if(temp[i]>=35)
			hot++;
	}
	
	printf("Total Cold Day (<=20) = %d\nTotal Mild Day (20 - 35) = %d\nTotal Hot Day (>35) = %d",cold,mild,hot);
	
}
