//Celcius to Fahrenhiate converter!
//done
#include <stdio.h>

int ctof(float);
int main(){

    int cel;
    printf("ENter Celsius Temperature: ");
    scanf(" %d",&cel);
    float feh=ctof(cel);
    printf("%d to Fahrenhiate is %.3f",cel,feh);
    
}


int ctof(float c){
    printf("Converting....... \n");
    return ((9.0/5.0)*c)+32;
}