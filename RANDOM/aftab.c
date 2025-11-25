#include<stdio.h>
int main(){
    int a,b,c,max;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);

    if(a%2==0 && b%2==0 && c%2==0){
    printf("there are no odd numbers");
    return 0;
}   
    max=a;
    if(max<b)
    max=b;
    if(c>max)
    max=c;

    
}