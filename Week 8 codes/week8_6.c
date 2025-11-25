#include <stdio.h>

int main() 
{
	// Array declaration and initialization
    // In this case, size is optional
    int ar[] = {14, 12, 15, 33, 22};	
    //int ar[5] = {14, 12, 15, 33, 22};	 // Also fine
    
    printf("ar: %d, %d, %d, %d, %d\n", 
			ar[0], ar[1], ar[2], ar[3], ar[4]);

	int ar2[5] = {7};
	int ar3[5] = {1, 2, 3};
	int ar4[5] = {}; // Not portable, error in some compilers
					 // The standard ways is: int ar[5] = {0};
	int ar5[5]; // Garbage values

    printf("ar2: %d, %d, %d, %d, %d\n", 
			ar2[0], ar2[1], ar2[2], ar2[3], ar2[4]);
    printf("ar3: %d, %d, %d, %d, %d\n", 
			ar3[0], ar3[1], ar3[2], ar3[3], ar3[4]);
    printf("ar4 (Non-standard): %d, %d, %d, %d, %d\n", 
			ar4[0], ar4[1], ar4[2], ar4[3], ar4[4]);
    printf("ar5 (Garbage): %d, %d, %d, %d, %d\n", 
			ar5[0], ar5[1], ar5[2], ar5[3], ar5[4]);
	
    return 0;
}


