#include <stdio.h>
#include <string.h>

int main() {

    int n;
    scanf("%d",&n);
    char str[n][10000];

    for(int i=0;i<n;i++){
        scanf("%s",str[i]);
    }
    for(int i=0;i<n;i++){
        int lng=strlen(str[i]);
        if(lng<=10){
            printf("%s",str[i]);
        }else{
            printf("%c%d%c",str[i][0],lng-2,str[i][lng-1]);
        }
        printf("\n");
    }




    }
