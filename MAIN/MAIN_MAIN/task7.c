/*7. Take 2 2x2 matrices as input in a 2D array. Then, multiply the 2 matrices and print the final
output matrix.*/
//Name: Mohsin Ali
//Rolll Number: 25P-0545
#include <stdio.h>
int main(){
    printf("Name: Mohsin Ali\nRoll Number: 25P-0545\n_______________________________\n");

    int arr1[2][2],arr2[2][2];
    int arr3[2][2]={0};
    
    printf("Enter 4 elements of Matrix 1: ");
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&arr1[i][j]);
        }

    }
        printf("Enter 4 elements of Matrix 2: ");

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&arr2[i][j]);
        }
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                arr3[i][j]+=arr1[i][k]*arr2[k][j];
            }

            }
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            printf("%d ",arr3[i][j]); 
        }
        printf("\n");
    

    
}

}