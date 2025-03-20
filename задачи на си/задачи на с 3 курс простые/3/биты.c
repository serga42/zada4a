#include <stdio.h>

// Функция для установки бита
void set_bit(unsigned int *num, int bit, int value) {
    if (value == 1) {
        *num |= (1 << bit);
    } else {
        *num &= ~(1 << bit);
    }
}

// Функция для получения бита
int get_bit(unsigned int *num, int bit) {
    return (*num >> bit) & 1;
}

// Функция для вывода в двоичном виде
void print_binary(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0) printf(" "); //разделил на байты ну тип вон на 8 дели еблан понял?
    }
    printf("\n");
}

int main() {
    unsigned int num = 0; // босс число жаль не 42

    // Устанавливаем биты
    set_bit(&num, 3, 1);  //3 бит в 1
    set_bit(&num, 5, 1);  //5 бит в 1
    set_bit(&num, 7, 0);  //7 бит в 0
    set_bit(&num, 10, 1); //10 бит в 1

    // вывводим значения битав
    printf("bit 3: %d\n", get_bit(&num, 3));  // Должно быть 1 так как мы их меняли ранее
    printf("bit 5: %d\n", get_bit(&num, 5));  // Должно быть 1
    printf("bit 7: %d\n", get_bit(&num, 7));  // Должно быть 0
    printf("bit 10: %d\n", get_bit(&num, 10)); // Должно быть 1

    //выввод в двоичной хуйне
    printf("Binary representation:\n");
    print_binary(num);
    getchar();

    return 0;
}