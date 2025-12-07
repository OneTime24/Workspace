// fax calculation:
//almost done
#include <stdio.h>

float calc(int n){
    float ini=0;
    for(int i=1;i<=n;i++){
        if(i<=10){
            ini+=0.20;
        }else if(i>10){
            ini+=0.10;
        }
    }
    return ini;
}
int main(){
    int n;
    printf("Enter number of pages: ");
    scanf("%d",&n);

    int s_C=3;

    float tprice=calc(n);
    float final=tprice+s_C;

    printf("Total Charges: service charge (%d) + page charge(%f) = %f",s_C,tprice,final);
}