#include <stdio.h>
#include <math.h>

int main() {
    double num1, num2, num3;

    printf("Enter 3 numbers separated by a space :\n");
    if (scanf("%lf%lf%lf", &num1, &num2, &num3) != 3) {
        printf("Invalid value\n");
        return 0;
    }

    if (num1 <= 0 || num2 <= 0 || num3 <= 0) {
        printf("Invalid value");
        return 0;
    }

    double arithmetic_mean = (num1 + num2 + num3) / 3.0;
    double geometric_mean = pow(num1 * num2 * num3, 1.0/3.0);

    printf("Arithmetic Mean: %.2f\n", arithmetic_mean);
    printf("Geometric Mean: %.2f\n", geometric_mean);

    return 0;
}