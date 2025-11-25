#include <stdio.h>   

int main() 
{
	float gpas[5], total_gpa, avg_gpa;
	int i;
	
	for(i = 0; i < 5; i++) // User inputs
	{
		printf("Enter GPA of Course No. %d: ", i+1);
		scanf("%f", &gpas[i]);
	} 
	
	printf("\n\nCourse  GPA\n");
	for(i = 0; i < 5; i++)		// Display
		printf("%6d %3.2f \n", i+1, gpas[i]);

	total_gpa = 0.0;
	for(i = 0; i < 5; i++)		// Adding
		total_gpa += gpas[i];

	avg_gpa = total_gpa / 5;
	printf("\n Avg GPA = %3.2f", avg_gpa);

    return 0;
}


