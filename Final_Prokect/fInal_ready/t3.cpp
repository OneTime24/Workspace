//Prob1

#include <stdio.h>

int main(){
	float m=1.5;
	float increase=0;
	for(int i=2025;i<=2050;i++){
		increase+=m;
		printf("Year: %d  | Number of milimeters incrase %f\n",i,increase);
	}
}
