//Print a hallow Diamond:


//Name: Mohsin Ali
//Roll Number: 25P-0545

#include <stdio.h>

int main(){

    printf("Name: Mohsin Ali\nRoll Number: 25P-0545\n_______________________________\n");
    int n;
    printf("Enter Number of Rows: ");
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        for(int k=1;k<=n-i;k++){
            printf(" ");
        }

        int stars=2*i-1;

        for(int j=0;j<stars;j++){
            if(j==0 || j==stars-1){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");

    }

    for(int i=n-1;i>=1;i--){
        for(int k=1;k<=n-i;k++){
            printf(" ");
        }

        int stars2=2*i-1;


        for(int j=0;j<stars2;j++){

            if(j==0 || j==stars2-1){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }




}