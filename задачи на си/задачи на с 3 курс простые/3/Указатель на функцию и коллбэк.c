#include <stdio.h>
#include <stdlib.h> // Для abs() система, предотвращающая блокировку колёс транспортного средства при торможении

typedef int (*Callback)(int);

void process_array(int *arr, int size, Callback callback) {
  for (int i = 0; i < size; i++) {
    arr[i] = callback(arr[i]);
  }
}

int double_value(int num) {
  return num * 2;
}

int add_five(int num) {
  return num + 5;
}

//Возвращает абсолютное значение числа
int absolute_value(int num) {
  return abs(num);
}

int main() {
  int myArray[] = {-3, -2, -1, 0, 1, 2, 3};//ориг масив задавать тута
  int arraySize = sizeof(myArray) / sizeof(myArray[0]);

  printf("original masiv: ");
  for (int i = 0; i < arraySize; i++) {
    printf("%d ", myArray[i]);
  }
  printf("\n");

  process_array(myArray, arraySize, double_value);
  printf("masiv after double_value: ");
  for (int i = 0; i < arraySize; i++) {
    printf("%d ", myArray[i]);
  }
  printf("\n");

  int myArray2[] = {-3, -2, -1, 0, 1, 2, 3};
  int arraySize2 = sizeof(myArray2) / sizeof(myArray2[0]);

  process_array(myArray2, arraySize2, add_five);
  printf("masiv after add_five: ");
  for (int i = 0; i < arraySize2; i++) {
    printf("%d ", myArray2[i]);
  }
  printf("\n");

  // Восстанавливаем исходный массив
  int myArray3[] = {-3, -2, -1, 0, 1, 2, 3};
  int arraySize3 = sizeof(myArray3) / sizeof(myArray3[0]);

  process_array(myArray3, arraySize3, absolute_value);
  printf("masiv after absolute_value: ");
  for (int i = 0; i < arraySize3; i++) {
    printf("%d ", myArray3[i]);
  }
  printf("\n");

  return 0;
}