#include <stdio.h>

long factorial(int n) {
    long res = 1;
    for (int i = 1; i <= n; ++i) {
        res *= i;
    }
    return res;
}

int main(int argc, char** argv) {

	for(int i = 1; i<=10; i++){
		
		printf("%5d%10ld\n", i, factorial(i));
	}
	
	return 0;
}