#include <stdio.h>

//считаем бешеные иксы в ракетке
void multiply_array_elements(float *arr, int size, float coefficient) {
  for (int i = 0; i < size; i++) {
    arr[i] *= coefficient;
  }
}

int main() {
  float myArray[] = {1.0, 2.0, 3.0, 4.0, 5.0};
  int arraySize = sizeof(myArray) / sizeof(myArray[0]);

  printf("original array: ");
  for (int i = 0; i < arraySize; i++) {
    printf("%.1f ", myArray[i]);
  }
  printf("\n");


  float multiplier = 2.42; // Задаем коэффициент
  multiply_array_elements(myArray, arraySize, multiplier);

  printf("Modified array (multiplied by X%.2f): ", multiplier);
  for (int i = 0; i < arraySize; i++) {
    printf("%.2f ", myArray[i]);
  }
  printf("\n");

  return 0;
}