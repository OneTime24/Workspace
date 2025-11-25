#include <stdio.h>

int main() 
{
	int i, j;

	float sum = 0.0;
	
    for (i = 1, j = 6; i <= 5; i++, j++) 
        sum += (float)i/j;
    
    printf("The sum is %f\n", sum);

    return 0;
}
