#include <stdio.h>
int main(){

    int n,x;
    scanf("%d %d",&n,&x);
    int mid=n/2;
    int ev[mid];
    int od[mid];
    int arr[n];


    for(int i=0;i<mid;i++){
        ev[i]=2*i;            
}
    for(int i=0;i<mid;i++){
        od[i]=(2*i)+1;
}

    // for(int i=0;i<mid;i++){
    //      printf("%d",ev[i]);
         
    // }
    // printf("\n");
    // for(int i=0;i<mid;i++){
    //      printf("%d",od[i]);
         
    // }

    int k = 0;
    for(int i = 0; i < mid; i++) {
        arr[k++] = od[i];  // add odd
    }
    for(int i = 0; i < mid; i++) {
    arr[k++] = ev[i];  // add even
}


    for(int i=0;i<n;i++){
         printf("%d ",arr[i]);
         
    }

    for(int i=0;i<n;i++){
        if(arr[i]==x){
            printf("\n%d",arr[i+1]);
        }
    }
}
