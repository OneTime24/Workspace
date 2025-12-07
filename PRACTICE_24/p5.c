// largest odd!
//almost done
#include <stdio.h>
int main(){

    int x,y,z,max=0;
    printf("Enter Three Numbers: ");
    scanf("%d %d %d",&x,&y,&z);

    if (x % 2 != 0) max = x;
    if (y % 2 != 0 && y > max) max = y;
    if (z % 2 != 0 && z > max) max = z;

    if (max == 0) {
        printf("None of them is ODD");
    } else {
        printf("%d is the greatest odd number among them", max);
    }
        return 0;

    }
