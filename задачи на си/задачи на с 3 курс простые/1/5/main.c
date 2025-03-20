#include <stdio.h>
#include "counter.h"

int main() {
  // Вызываем функцию incrementCounter несколько раз
  incrementCounter();
  incrementCounter();
  incrementCounter();

  // Получаем текущее значение счетчика
  int current_count = getCount();
  printf("Значение счетчика: %d\n", current_count);

  incrementCounter();
  current_count = getCount();
   printf("Значение счетчика: %d\n", current_count);

  return 0;
}

