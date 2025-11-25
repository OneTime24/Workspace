/*Take an array with N elements as input, and sort the array into ascending order and then
print the sorted version.*/

//Name: Mohsin ALi
//ROll Number: 25P-0545


#include <stdio.h>
int main(){
    printf("Name: Mohsin Ali\nRoll Number: 25P-0545\n_______________________________\n");

    int n;
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
    int temp=arr[0];

    for(int i=0;i<n;i++){
        for(int j=0;j<(n-i)-1;j++){
        if(arr[j]>arr[j+1]){
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        }
    }

}

for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
}


}