#include <stdio.h> 
int main()
{
	int a, b, s;
	printf("Enter first number ");
	scanf("%d", &a);
	printf("Enter second number ");
	scanf("%d", &b);
	s = a + b;

	// We are not going to print directly to terminal
	// printf("The sum of %d and %d is %d\n", a, b, s);

//////////////////// Writing to a File ///////////////////////////
	FILE *fp1 = fopen("output.txt", "w");
	// fp1 is the file pointer, name = output.txt, w = writing
	// Overwrite the file if it already exists

	fprintf(fp1, "The sum of %d and %d is %d\n", a, b, s);
	// writing to a file
	fclose(fp1);
	printf("Output saved to output.txt \n");
/////////////////////////////////////////////////////////////////

//////////////////// Appending to a File ///////////////////////////
	FILE *fp2 = fopen("all_outputs.txt", "a");
	// fp is the file pointer, name = output.txt, a = Appending
	// Writes to the end of an existing file
	// Creates new, if doesn't exist already

	fprintf(fp2, "The sum of %d and %d is %d\n", a, b, s);
	// writing to a file

	fclose(fp2);
	printf("Output appended to all_outputs.txt \n");
/////////////////////////////////////////////////////////////////

	return 0;
}
