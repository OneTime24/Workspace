#include <stdio.h>
int main(){
	
	int n,flag;

	scanf("%d",&n);
	
	for(int i=2;i<n;i++){
		if(n%i==0){
			flag=1;
		}
	}
	if(flag==1){
		printf("%d is not a prime number: ",n);
	}else{
		printf("%d is a prime number: ",n);
	}

	

}

