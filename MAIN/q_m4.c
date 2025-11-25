#include <stdio.h>
int main(){
    
    // int n;
    // scanf("%d",&n);

    // char str1[3];
    // char str2[3];

    
    // for(int i=0;i<1;i++){
    //     scanf("%s",str1);
    // }
    // for(int i=0;i<1;i++){
    //     scanf("%s",str2);
    // }
    // int t1=0;
    // for(int i=0;i<1;i++){
    //     if(str1[i]=="++X"){
    //         t1=++n;
    //     }
    // }
    // for(int i=0;i<1;i++){
    //     if(str1[i]=="X++"){
    //         t1=n++;
    //     }
    // }
    // for(int i=0;i<1;i++){
    //     if(str2[i]=="--X"){
    //         t1=--n;
    //     }
    // }
    // for(int i=0;i<1;i++){
    //     if(str2[i]=="X--"){
    //         t1=n--;
    //     }
    // }

    // printf("%d",t1);

    int n;
    scanf("%d",&n);
    int t=0;
    for(int i=0;i<n;i++){

        char str[4];
        
        scanf("%s",str);
        
        if ((str[0]=='+' && str[1]=='+' && (str[2]=='X' || str[2]=='x')) ||
            ((str[0]=='X' || str[0]=='x') && str[1]=='+' && str[2]=='+')) {
            t++;
        }
        else if ((str[0]=='-' && str[1]=='-' && (str[2]=='X' || str[2]=='x')) ||
                 ((str[0]=='X' || str[0]=='x') && str[1]=='-' && str[2]=='-')) {
            t--;
        }
    }
    printf("%d",t);

}