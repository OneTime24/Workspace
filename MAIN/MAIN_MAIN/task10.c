/*Given an unsorted array A of size N that contains only non-negative integers, find a
continuous sub-array which adds to a given number S. In case of multiple subarrays, return
the subarray which comes first on moving from left to right.*/

//Name: Mohsin Ali
//Roll Number: 25P-0545

#include <stdio.h>

int main(){

    printf("Name: Mohsin Ali\nRoll Number: 25P-0545\n_______________________________\n");

    int sz;
    int t;
    printf("Enter Array Size: ");
    scanf("%d",&sz);

    int arr[sz];
    printf("Enter Target: ");
    scanf("%d",&t);

    for(int i=0;i<sz;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<sz;i++){
        int sm=0;
        for(int j=i;j<sz;j++){
            sm+=arr[j];

            if(sm==t){
                printf("Subarray from index %d to %d sums to %d\n", i, j, t);
                
                printf("\n");
                return 0;
            }

        }
    }
printf("Error- Try Again: ");
return 0;
}