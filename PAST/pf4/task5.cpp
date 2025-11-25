#include <stdio.h>
int main(){
	
	char type,size;
	
	float timeW,timeB,timeW_f1,timeW_f2;
	printf("Enter Coffee Type:(b for black : w for white) ");
	scanf("%c",&type);
	printf("Enter Cup Size: (d for double : m for manual)");
	scanf("%c",&size);
	
	switch(type){
		case 'w':
			timeW=15+15+20+2+4+20;
			switch(size){
				case 'd':
				timeW_f1=timeW*(50/100);
				timeW_f2=timeW+timeW_f1;
				printf("Total Time Taken for White Coffee with Cup Size Double: %f",timeW_f2);
			}
			
	}
	
}
