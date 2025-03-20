#include <stdio.h>

int main() {
    int max_number;

    printf("Enter the maximum number for the table: ");
    scanf("%d", &max_number);

    printf("\nNumber\tSquare\tCube\n");

    for (int i = 1; i <= max_number; ++i) {
        int square = i * i;
        int cube = i * i * i;

        printf("%d\t%d\t%d\n", i, square, cube);
    }

    return 0;
}