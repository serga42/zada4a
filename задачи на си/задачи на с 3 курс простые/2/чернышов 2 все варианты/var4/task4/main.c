#include <stdio.h>
#include <ctype.h>

int main() {
    char input;
    char digits[1000];
    int count = 0;

    printf("Enter number (for exit: #):\n");

    while (1) {
        input = getchar();

        if (input == '#') {
            break;
        }

        if (isdigit(input)) {
            printf("Your input:%c\n", input);
            if (count < 1000) {
              digits[count] = input;
              count++;
            } else {
                printf("Limit exceeded\n");
                break;
            }
        }
    }

    printf("\nNumbers in reverse order:\n");
    for (int i = count - 1; i >= 0; i--) {
        printf("%c", digits[i]);
    }
    printf("\n");

    return 0;
}