//PALINDROME!!

#include <stdio.h>
int main(){

    int max=0;
    for(int i=100;i<=999;i++){
        int result;
        for(int j=100;j<=999;j++){
            result=i*j;
            if(result>max){
                int a,b,c,d,e,f,g,h,k,l;      //assume 99*99=998,001
                a=result%10;   //a=1
                b=result/10;    //b=99,800
                c=b%10;         //c=0
                d=b/10;         // d=998,0
                e=c%10;         //e=0
                f=c/10;         //f=998
                g=f%10;         //g=8
                h=f/10;         //h=99
                k=h%10;         //k=9
                l=h/10;         //l=9
            if(a==l && c==k){
                
            }
            }
        }
    }


}