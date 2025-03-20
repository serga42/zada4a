#include <stdio.h>
#include <math.h>

int main() {
  printf(" n\t2^n\n");

  for (int n = 0; n <= 10; n++) {
    int result = pow(2, n);
    printf("%2d \t %2d\n", n, result);
  }
  return 0;
}
