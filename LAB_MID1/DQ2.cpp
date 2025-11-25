/*Q2)Write a C program in which take input (N) from user now check if the square of N consist the N in end then print yes.otherwise no.
 then use bitwise function and multiply (N) BY 16 and divide (N) by 4.

 */
 #include <stdio.h>
 int main(){
 	
	 int n,sq,mul=1,div,mod;
	 printf("Enter a Number: ");
	 scanf("%d",&n);
	 sq=n*n;
	 mod=sq%10;
	 
	 if(mod==n){
	 	printf("YES\n");
	 }else{
	 	printf("NO\n");
	 }
	 
	 mul=n<<4;
	 printf("%d\n",mul);
	 
	 div=n>>2;
	 printf("%d\n",div);
	 
 	
 	
 	
 }
