//Leap year
//done

#include <stdio.h>

void isleap(int y){
    if((y%400==0) || (y%4==0 && y%100!=0) ){
        printf("%d is a leap Year: ",y);
    }else{
        printf("Not a Leap Year....");
    }
}
int main(){

    int y;
    scanf("%d",&y);
    isleap(y);

    return 0;



}