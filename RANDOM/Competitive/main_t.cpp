#include <stdio.h>
#include <string.h>
int main(){
    // int arr[100];
    // char ch;
    // scanf("%d",&ch);
    // while(ch!='\n'){
    //     for( int i=0;i<100;i++){
    //         printf("Enter Value (0,1): ");
    //         scanf("%d",arr[i]);
    //     }
    // }
    int flg=0;
    char str[100];
    gets(str);
    int leng=strlen(str);
    for(int i=0;i<leng;i++){
        if(str[i]==str[i+1]){
            flg++;
            if(flg==7){
            	printf("YES");
            	return 0;
			}
        }else{
        	flg=1;
		}

    }
//    if(flg==7){
//        printf("YES");
//    }else{
        printf("NO");
//    }
}
