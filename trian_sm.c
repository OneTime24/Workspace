#include <stdio.h>
int main(){
    for(int i=0;i<10;i++){
        int sm=1;
        for(int j=i;j>0;j--){
            sm+=j;
        }
         printf("%d\n",sm);
    }
}