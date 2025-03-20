#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int number1, number2;

 	printf("Enter 1 number: ");
    if (scanf("%d", &number1) != 1 || number1 <= 0) {
        printf("Invalid value\n");
        return 0;
    }

    printf("Enter 2 number: ");
    if (scanf("%d", &number2) != 1 || number2 <= 0) {
        printf("Invalid value\n");
        return 0;
    }
 
    int nod = gcd(number1, number2);
    int nok = lcm(number1, number2);

    printf("greatest common divisor: %d\nleastCommonMultiple: %d\n", nod, nok);

    return 0;
}