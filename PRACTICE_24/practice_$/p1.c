//Global warming

#include <stdio.h>
int main(){
    float m=1.5;
    float tot_in=0;
    printf("Year\t|Change\n");
    for(int i=0;i<25;i++){
        tot_in+=m;
        printf("%d\t|%.4f",2025+i,tot_in);
        tot_in+=m;
        printf("\n");
    }
}