#include <stdio.h>
int main(){

    int n;
    scanf("%d",&n);
    int arr[n][3];

    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&arr[i][j]);
        }
    }
int cnt=0;
int count=0;
        for(int i=0;i<n;i++){
            cnt=arr[i][0]+arr[i][1]+arr[i][2];
        
        if(cnt>=2){
            count++;
        }
        
        }
    printf("%d ",count);


}