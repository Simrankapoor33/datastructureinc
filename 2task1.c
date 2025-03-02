#include <stdio.h>

int main() {
    printf("task1: adding elements in 2D array\n");
    int a[3][3], i, j;
    printf("Enter elements of 2D array:\n");

    // Input elements in the 2D array
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Display elements of the 2D array
    printf("Entered elements are:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}