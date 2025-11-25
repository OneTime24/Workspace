#include <stdio.h>
#include <string.h>
int main(){

    char str[100];
    char str2[100];

    scanf("%[^\n]s",str);
    int ln=strlen(str);
    int cn=0;    
    char temp;
        for(int i =0;i<ln-1;i++){
            for(int j=0;j<(ln-1)-i;j++){
                if(str[j]>str[j+1]){
                temp=str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
            }
        }
        }
    // for(int i=0;i<ln;i++){
        // printf("%s",str);
    // }
        for(int i=0;i<ln-1;i++){
            if(str[i]==str[i+1])
            cn++;
        }
        int disc=ln-cn;
         if(disc%2==0){
             printf("CHAT WITH HER!");
    }else{
        printf("IGNORE HIM!");
    }
}