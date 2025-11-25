/*Task-2
There are 2 wolves and 1 sheep in a line. Both wolves will attempt to eat the
sheep. You are supposed to find out which wolf will reach the sheep and eat it,
assuming both wolves move at the same speed and the sheep does not move.
Take as input the positions of wolf A, wolf B and the sheep on the line (x-
coordinate) and find out which wolf will reach the sheep first and eat it.
If Wolf A reaches the sheep first, print “Wolf A”
If Wolf B reaches the sheep first, print “Wolf B”
If both wolves reach the sheep at the same time, the wolves will get distracted
and fail to eat the sheep, so print “Wolves distracted, Sheep escaped” */

#include <stdio.h>
int main(){
	printf("NAME: Mohsin Ali \nRoll Number: 25P-0545\n");
	printf("________________________________________________\n");
	int wolf_a,wolf_b,sheep,distA,distB;
	printf("Enter Sheep's Distance: ");
	scanf(" %d",&sheep);
	printf("Enter Wolf A's Distance: ");
	scanf(" %d",&wolf_a);
	printf("Enter Wolf B's Distance: ");
	scanf(" %d",&wolf_b);
	
	
	if(sheep>=wolf_a){
		distA=sheep-wolf_a;
	}else{
		distA=wolf_a-sheep;
	}
	if(sheep>=wolf_b){
		distB=sheep-wolf_b;
	}else{
		distB=wolf_b-sheep;
	}
	
	if(distA<distB){
		printf("Wolf A is Closer to Sheep. ");
	}else if(distA>distB){
		printf("Wolf B is Closer to Sheep. ");
	}else if (distA==distB){
		printf("Both are at the same distance. ");
	}else{
		printf("Wolf Distracted: Sheep Escaped. ");
	}
	
		
	
}
