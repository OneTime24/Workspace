/* Given an array of integers of size N and an integerù, the task is to rotate the array
elements to the left by d positions. Note: Solve the question without declaring another
array. (The input array itself must be modified).*/

//Name: Mohsin Ali
//Roll Number: 25P-0545
#include <stdio.h>
int main(){
    printf("Name: Mohsin Ali\nRoll Number: 25P-0545\n_______________________________\n");
    int n;
    printf("Enter Size of array: ");
    scanf("%d",&n);


    printf("Enter the number of times to shift the array: ");
    int d;
    scanf("%d",&d);

    int arr[n];

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    // int ln=(sizeof(arr)/sizeof(arr[0]));

    for(int i=0;i<d;i++){
        int temp=arr[0];
        for(int i=0;i<n-1;i++){
                arr[i]=arr[i+1];
    }
    arr[n-1]=temp;
}

for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}

}
