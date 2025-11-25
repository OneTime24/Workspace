#include <stdio.h>
#include <math.h>

int main( )
{
	int n;
/*	
	while(1)
	{
		printf("Enter n ");	scanf ( "%d", &n);
		if(n < 0) break;
		printf("Square of n = %f\n", sqrt(n));
	}
*/
	
	for(;;)
	{
		printf("Enter n ");	scanf ( "%d", &n);
		if(n < 0) break;
		printf("Square of n = %f\n", sqrt(n));
	}	
	
	return 0;
}

