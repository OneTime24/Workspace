#include <stdio.h>
int main(){
	
	int a=0,b=1,temp=0;
	for(int i=1;i<10;i++){
		printf("%d ",b);
		a=b;
		b+=temp;
		temp=a;
	}
	
	
}
