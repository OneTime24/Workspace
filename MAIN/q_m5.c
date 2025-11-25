#include <stdio.h>
int main(){

    int n,k;
    int arr[50];
    scanf("%d %d",&n,&k);
    int count=0;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int th=arr[k-1];
    for(int i=0;i<n;i++){
        if(arr[i]>=th && arr[i]>0){
            count++;
        }
    }
    printf("%d",count);
}