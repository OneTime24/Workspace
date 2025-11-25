//Take a number from user and count the sum of their digits.
//Name: Mohsin ALi
//ROll Number: 25P-0545
#include<stdio.h>
int main(){
    printf("Name: Mohsin Ali\nRoll Number: 25P-0545\n_______________________________\n");
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    int sum=0;
    while(n>0){
        sum+=n%10;
        n=n/10;
    }

    printf("Sum is: %d",sum);
    return 0;

}