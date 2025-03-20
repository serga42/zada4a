#include <stdio.h>

int main() {
    printf("   |");
    for (int i = 1; i <= 5; ++i) {
        printf("\t%d", i);
    }
    printf("\n");
    
    printf("---*");
    for (int i = 0; i < 40; ++i) {
        printf("-");
    }
    printf("\n");

    for (int i = 1; i <= 5; ++i) {
        printf("%2d |", i); 
        
        for (int j = 1; j <= 5; ++j) {
            printf("\t%d", i * j);
        }
        
        printf("\n");
    }

    return 0;
}