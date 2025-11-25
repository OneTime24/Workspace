#include <stdio.h>
int main(){
	
	int n,flag=1;
	scanf("%d",&n);
	for(int i=2;i<n;i++){
		if(n%i==0){
			flag=0;
			printf("Number is not Prime: Bye");
			return 0;
		}
		
	}
	
	if(flag==1){
		printf("NUmber is Prime: ");
	}
}
	
	

