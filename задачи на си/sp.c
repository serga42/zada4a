#include <stdio.h>
//считает скока digit находиться в n

int car(int n, int digit) {
	int x = 0;

	while (n > 0) {
		if (n % 10 == digit) {
		    x++;}
		n /= 10;
	}
	return x;
}

int main() {
	int n, digit;
	printf("Enter a natural number: ");
	scanf("%d", &n);
	if (n < 1) {
		printf("error no natural number\n", n);
	}
	
	printf("Enter the digit to count: ");
	scanf("%d", &digit);

	int x = car(n, digit);
	printf("The number %d appears %d times in %d.\n", digit, x, n);

	return 0;
}