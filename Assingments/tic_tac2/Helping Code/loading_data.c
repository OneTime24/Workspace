#include <stdio.h>
int main()
{
	int x, y, sum;
	char str[20];

	FILE* fp = fopen("all_outputs.txt", "r"); // r = Reading
	
	while(1)
	{		
		fscanf(fp, "%s ", str);	//The
		fscanf(fp, "%s ", str);	//sum
		fscanf(fp, "%s ", str);	//of
		fscanf(fp, "%d ", &x);	//int value of x
		fscanf(fp, "%s ", str);	//and
		fscanf(fp, "%d ", &y);	//int value of y
		fscanf(fp, "%s ", str);	//is
		fscanf(fp, "%d ", &sum);	//int value of sum

		printf("%d + %d = %d\n", x, y, sum);
		
		if(feof(fp)) // If reached the end of file, then stop reading
			break;
	}

	fclose(fp);
	return 0;
}


