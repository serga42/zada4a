#include <stdio.h>

int main() {
    int day, month, year;
    int h, q, m, j, k;


printf("\t\tGiven 3 natural numbers denoting a date,tell what day of the week this date falls on\n");
    // Ввод даты
    printf("Enter day: ");
    scanf("%d", &day);
    printf("Enter month: ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);

    // Алгоритм Зеллера
    if (month <= 2) {
        month += 12;
        year--;
    }

    // Вычисление значений j и k
    j = year / 100;
    k = year % 100;

    // Вычисление дня недели
    h = day + 13*(month + 1) / 5 + k + k / 4 + j / 4 - 2 * j;
    q = h / 7;
    m = h - q * 7;

    // Вывод дня недели
    switch(m) {
        case 0:
            printf("Monday\n");
            break;
        case 1:
            printf("Tuesday\n");
            break;
        case 2:
            printf("Wednesday\n");
            break;
        case 3:
            printf("Thursday\n");
            break;
        case 4:
            printf("Friday\n");
            break;
        case 5:
            printf("Saturday\n");
            break;
        case 6:
            printf("Sunday\n");
            break;
    }

    return 0;
}