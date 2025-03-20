#include <stdio.h>
int is_vowel(char c) {
    switch (c) {
        case 'a': case 'A':
        case 'e': case 'E':
        case 'i': case 'I':
        case 'o': case 'O':
        case 'u': case 'U':
        case 'y': case 'Y':
            return 1;
        default:
            return 0;
    }
}

int main() {
    char ch;
    while ((ch = getchar()) != '*') {
        if (is_vowel(ch)) {
            putchar(ch);
            printf("\n");
        }
    }

    return 0;
}