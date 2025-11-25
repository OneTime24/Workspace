#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    float arr[n];
    float arr1[n];
    for(int i=0;i<n;i++){
        scanf("%f",&arr[i]);
    }

    for(int i=1;i<n;i++){
        arr1[i]=1/arr[i];
    }
printf("\n_______________\n");
    for(int i=1;i<n;i++){
        printf("%f ",arr1[i]);
    }
}