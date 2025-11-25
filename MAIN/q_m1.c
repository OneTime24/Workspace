#include <stdio.h>
int main(){

    int x;
    scanf("%d",&x);
    if(x==2){
        printf("NO");
        return 0;
    }
    if(x%2==0){
        printf("YES");
    }else{
        printf("NO");
    }


}