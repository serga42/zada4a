#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;

    do {
        ch = getchar();
        if (ch == '\n') {
            continue;
        }
        
        if (islower(ch)) {
        	printf("Uppercase letter: ");
            putchar(toupper(ch));
            printf("\n");
        } else {
        	printf("The letter was already in uppercase: ");
            putchar(ch);
            printf("\n");
        }
    } while (tolower(ch) != 'x');

    return 0;
}

