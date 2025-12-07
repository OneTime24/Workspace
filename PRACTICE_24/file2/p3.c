// Quadratic Equation:

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

    int a,b,c;
    printf("Enter value of a, b and c: ");
    scanf("%d %d %d",&a,&b,&c);

    if(a == 0){
        printf("Not a quadratic equation.\n");
        return 0;
    }

    int disc = (b*b) - 4*a*c;
    float real, imag;

    if(disc > 0){
        float r1 = (-b - sqrt(disc)) / (2.0 * a);
        float r2 = (-b + sqrt(disc)) / (2.0 * a);
        printf("ROOT 1: %.3f\n", r1);
        printf("ROOT 2: %.3f\n", r2);

    } else if(disc == 0){
        float r = -b / (2.0 * a);
        printf("Both roots are %.3f\n", r);

    } else { // disc < 0 → complex roots
        real = -b / (2.0 * a);
        imag = sqrt(-disc) / (2.0 * a);

        printf("ROOT 1: %.3f + %.3fi\n", real, imag);
        printf("ROOT 2: %.3f - %.3fi\n", real, imag);
    }

    return 0;
}
