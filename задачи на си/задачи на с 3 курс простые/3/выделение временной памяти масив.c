#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int rows, cols;
  int **matrix; // Указатель на указатель

  printf("Enter the number of strok : ");
  scanf("%d", &rows);
  printf("Enter the number of stolbes: ");
  scanf("%d", &cols);

	//это спасателоь без него как сайчас если он отключон то масив можно делать бесконечным на скока позволяет твой пк масив создовать не более 5чисел 
  //if (rows <= 0 || cols <= 0) {
  //  printf("Error: yuo eblan con4eni bros programming tyta doljno bit polojitelnim strok and stolbes.\n");
   // return 1;
 // }

  // Выделяем память
  matrix = (int **)malloc(rows * sizeof(int *));
  if (matrix == NULL) {
    printf("Error: no memory for masiva strok.\n");
    return 1;
  }

  // Выделяем память для каждой строки
  for (int i = 0; i < rows; i++) {
    matrix[i] = (int *)malloc(cols * sizeof(int));
    //это спасателоь без него как сайчас если он отключон то масив можно делать бесконечным на скока позволяет твой пк масив создовать не более 5чисел 
   // if (matrix[i] == NULL) {
   //   printf("error no memory for strok %d.\n", i);
   
    //  for (int j = 0; j < i; j++) {
     //   free(matrix[j]);
    //  }
    //  free(matrix);
   //   return 1;
   // }
  }

  //Заполняем матрицу случайными числами
  srand(time(NULL));

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = rand() % 100; // Случайные числа от 0 до 99(от i до j)
    }
  }

  printf("matrisa:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%3d ", matrix[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < rows; i++) {
    free(matrix[i]); // Освобождаем память для каждой строки
    printf("%3d", matrix[i]);
  }
  free(matrix); // Освобождаем память для массива указателей

  return 0;
}