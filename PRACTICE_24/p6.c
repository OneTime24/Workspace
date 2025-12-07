// Types of triangles!
//done almost
void calc(int,int,int);
#include <stdio.h>
int main(){

    int x,y,z;
    printf("Enter three sides of triangle: ");
    scanf("%d %d %d",&x,&y,&z);
    if(x + y <= z || y + z <= x || z + x <= y){
        printf("NOT A VALID TRIANGLE");
        return 0;
    }
    calc(x,y,z);
}
void calc(int x, int y, int z){
    if(x==y && y==z){
        printf("EQUVALETERAL TRIANGLE: ");
    }else if((x==y) ||(y==z)||(z==x)){
        printf("Isoscelese Triangle:: ");
    }else{
        printf("Scalene Triangle: ");
    }
}