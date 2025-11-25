#include <stdio.h>
#include <string.h>
int main(){

    char str[100];
    scanf("%s",str);
    // int ln=strlen(str);
    // printf("%d",ln);
    int cnt=0;
    for(int i=1;str[i]!='\0';i++){
        if(str[i]==str[i-1]){
            cnt++;
            if(cnt==6){
                printf("YES");
                return 0;
            }
        }else{
            cnt=0;
        }

    }

printf("NO");
}