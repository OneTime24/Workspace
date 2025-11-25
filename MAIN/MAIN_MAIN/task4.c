// Take a 2D array(Matrix) as input from user and check that array is symmetric or not. If array
// is symmetric then print “Array is Symmetric” with array if not, then print “array is not
// symmetric” with given array.

#include <stdio.h>

int main(){
    printf("Name: Mohsin Ali\nRoll Number: 25P-0545\n_______________________________\n");

    int n;
    printf("Enter size of square matrix: ");
    scanf("%d", &n);

    int arr1[n][n];
    int arr2[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr1[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr2[i][j] = arr1[j][i];
        }
    }


    int flg = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr1[i][j] != arr2[i][j]){
                flg = 0;
                break;
            }
        }
        if(flg == 0) break;
    }

    if(flg)
        printf("Array is Symmetric!\n");
    else
        printf("Array is Not Symmetric!\n");

    return 0;
}

