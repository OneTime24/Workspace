/*Take an array with N elements as input, and then output the frequency of each element
present in the array.*/

//Name: Mohsin Ali
//Roll Number: 25P-0545

#include <stdio.h>

int main(){

    printf("Name: Mohsin Ali\nRoll Number: 25P-0545\n_______________________________\n");

    int n;
    printf("Enter Number of Elements: ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++){

        scanf("%d",&arr[i]);

    }

      for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    int temp=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
    }

    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    printf("\n");

int count = 1;

for(int i=0; i<n; i++){
    if((i < n-1) && (arr[i] == arr[i+1])) {
        count++;
    }
    else {
        printf("Frequency of %d = %d\n", arr[i], count);
        count = 1;
    }
}




}