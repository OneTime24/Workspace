#include <stdio.h>

int main() 
{
	int n, i, sum, product;

	printf("Enter n ");		scanf("%d", &n);

	sum = 0;
	product = 1;
	
    for (i = 0; i < n; i++, sum += i, product *= i);

/*    
    for(i = 1; i <= n; i++)
    {
    	sum += i;
    	product *= i;
	}
  */
    
    printf("Sum = %d, Product = %d\n", sum, product);

    return 0;
}

