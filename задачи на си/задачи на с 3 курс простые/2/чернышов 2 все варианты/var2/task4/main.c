#include <stdio.h>

int main() {
    char chars[100]; 
    int index = 0; 

    printf("Enter characters (end with #):\n");
    while (index < 99) {
        char ch = getchar();
        if(ch == '\n'){
        	continue;
		}
        if (ch == '#') {
            break; 
        }
        chars[index++] = ch; 
    }

    printf("Reversed order:\n");
    for (int i = index - 1; i >= 0; i--) {
        putchar(chars[i]);
    }

    return 0;
}
