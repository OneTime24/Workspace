#include<stdio.h>
int main(){
	int x=0,a;
	char arr[3];
	
	scanf("%d",&a);
	
	for(int i=0;i<a;i++){
	scanf("%s",arr);
 	if((arr[0]=='+'&&arr[1]=='+'&&(arr[2]=='X'||arr[2]=='x'))||((arr[0]=='X'|| arr[0]=='x')&&arr[1]=='+'&&arr[2]=='+')){
 		x+=1;
	 }
	  	if((arr[0]=='-'&&arr[1]=='-'&&(arr[2]=='X'||arr[2]=='x'))||((arr[0]=='X'|| arr[0]=='x')	&&arr[1]=='-'&&arr[2]=='-')){
 		x-=1;
	 }
	 
}
	printf("%d",x);
}
