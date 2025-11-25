#include <stdio.h>

int main() {
    int n;
    printf("Enter number of odd rows: ");
    scanf("%d", &n);

    int mid = (n + 1) / 2;

    // Print top single star
    for (int i = 1; i < mid; i++) {
        printf(" ");
    }
    printf("*\n");

    // Print remaining rows
    for (int i = 2; i <= mid; i++) {
        // Leading spaces
        for (int j = i; j < mid; j++) {
            printf(" ");
        }

        // First star
        printf("*");

        // Inner spaces
        for (int k = 1; k <= (2 * i - 3); k++) {
            printf(" ");
        }

        // Second star
        printf("*");

        printf("\n");
    }

    return 0;
}

