#include <stdio.h>
#include <string.h>
int main(){
	
	char str1[100];
	char str[100];
	
	printf("ENTER NAME: ");
	fgets(str1,sizeof(str1),stdin);
	str1[strcspn(str1, "\n")]='\0';
	printf("BEFORE COPY INPUT: %s",str1);
	strcpy(str,str1);
	printf("\nAFTER COPY INPUT NOT LOGIC APPLIED: %s",str);
	strlwr(str1);
	strlwr(str);
	int len=strlen(str1);
	int a=0,b=len-1;
	while(a<b){
		int temp=str1[a];
		str1[a]=str1[b];
		str1[b]=temp;
		a++,b--;
	}
	printf("\nAFTER LOGIC APPLIED: %s",str1);
	if(strcmp(str,str1)==0){
		printf("\nPALINDROME: ");
	}else{
		printf("\nNOT PALINDROME: ");
	}
}
