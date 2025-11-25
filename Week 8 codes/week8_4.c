#include <stdio.h>

int main() 
{
    int i = 1;
    int j = 5;

    for (i = 1; i % 2 == 0, j >= 0; i++, j--) 
        printf("Loop run: i = %d, j = %d\n", i, j);
    
    printf("\n After Loop: i = %d, j = %d\n", i, j);
    return 0;
}


