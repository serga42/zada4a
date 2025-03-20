#include <stdio.h>
#include "counter.h"

int main() {
  // Вызывает функцию
  incrementCounter();
  incrementCounter();
  incrementCounter();

  // Получаем текущее значение счетчика
  int current_count = getCount();
  printf("shet: %d\n", current_count);

  incrementCounter();
  current_count = getCount();
   printf("shet: %d\n", current_count);

  return 0;
}