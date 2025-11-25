#include <stdio.h>
int main(){
    int n,half;
    scanf("%d",&n);
    int arr[n];
    int count=0;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]); 
    }
    int total=0;
    for(int i=0;i<n;i++){
        total+=arr[i];
    }
    half=total/2;
    int temp=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<(n-1)-i;j++){

            if(arr[j]<arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        count++;

    if(sum>total-sum){
        break;
    }

    }
        
       printf("%d",count);
        
    }


   

 