#include <stdio.h>
#include <stdlib.h>

void calc(int *ptr, int gl){
	int total=0;
	for(int i=0;i<7;i++){
		total+=*(ptr+i);
	}
		printf("\nTotal= %d ",total);
		printf("\nAverage: %f",(float)total/7);
		
		int max=0,day=0;
		
		for(int i=0;i<7;i++){
			if(*(ptr+i)>max){
				day=i+1;
			}
		}
		
		printf("\nHighest Step Day: %d",day);
		
		if(total>gl){
			printf("\nGreat Job! You have met your goal!");
		}else{
			printf("\nYou are falling short, Try Harder: ");
		}
}
int main(){
	
	int *arr=(int*)calloc(7,sizeof(int));
	
	for(int i=0;i<7;i++){
		printf("Enter Steps for Day %d: ",i+1);
		scanf(" %d",(arr+i));
	}
	int gl;
	printf("Set your weekly goal: ");
	scanf(" %d",&gl);
	
//	for(int i=0;i<7;i++){
//		printf("%d ",*(arr+i));
//	}

	
	calc(arr,gl);
	
	
}
