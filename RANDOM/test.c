#include<stdio.h>
int main(){
    int a;
    printf("how many numbers are you comparing\n");
    scanf("%d",&a);
    int arr[a];
    for(int i=0;i<a;i++){
        scanf("%d",&arr[i]);
    }

    int temp=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<a-i-1;j++){
            if(arr[j]>arr[j+1]){
            temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
        }
    }
    }
    for(int i=0;i<a;i++)
    printf("%d ",arr[i]);
    printf("\n");
    
    int i=0;
    for(int i=a-1;i>=0;i--){
    if(arr[i]%2!=0){
        printf("%d",arr[i]);
        return 0;
    }
    }
    printf("there are no odd numbers");
    return 0;
        
    }
