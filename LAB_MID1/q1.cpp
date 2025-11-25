/* 3. Create a program to find the largest of three numbers.
 4. Write a program to determine if a year is a leap year */
 
// #include <stdio.h>
// int main(){
// 	
// 	int x,y,z;
// 	scanf("%d %d %d",&x,&y,&z);
// 	
// 	if(x>y && x>z){
// 		printf("%d is Greatest: ",x);
//	 }else if(y>z && y>x){
//	 	printf("%d is Greatest: ",y);
//	 	
//	 }else if(z>x && z >y ){
//	 	printf("%d is Greatest: ",z);
//	 }
// 	
// }

// Leap year

#include <stdio.h>
int main(){
	
	int year;
	scanf("%d",&year);
	
	if((year%400==0) || ((year%4==0)&&(year%100!=0))){
		printf("%d is a leap Year: ",year);
	}else{
		printf("%d is not a leap Year: ",year);
	}
	
	
}
