#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//используеться сортировкa слиянием


void merge(char **arr, int left, int middle, int right) {
  int i, j, k;
  int n1 = middle - left + 1;
  int n2 = right - middle;

  //временные массивы
  char **L = (char **)malloc(n1 * sizeof(char *));
  char **R = (char **)malloc(n2 * sizeof(char *));

  // Копируем данные во временные массивы L и R
  for (i = 0; i < n1; i++) L[i] = arr[left + i];
  for (j = 0; j < n2; j++) R[j] = arr[middle + 1 + j];

  i = 0; // Начальный индекс первого подмассива
  j = 0; // Начальный индекс второго подмассива
  k = left; // Начальный индекс объединенного подмассива
  while (i < n1 && j < n2) {
    if (strcmp(L[i], R[j]) <= 0) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Копируем  элементы из масива L
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Копируе элементы из масива R
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }

  free(L);
  free(R);
}

void mergeSort(char **arr, int left, int right) {
  if (left < right) {
    // То же самое, что и (left+right)/2, но позволяет избежать переполнения для больших left и right
    int middle = left + (right - left) / 2;

    // Сортируем первую и вторую част
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);

    merge(arr, left, middle, right);
  }
}

int main() {
  int num_strings;
  char **strings;

  printf("Enter the number of strok: ");
  scanf("%d", &num_strings);

  // Проверка на еблана ну вдруг попадешся епта
  if (num_strings <= 0) {
    printf("Error: The number of rows must be positive.\n");
    return 1;
  }

  // Выделяем память для массива
  strings = (char **)malloc(num_strings * sizeof(char *));
  if (strings == NULL) {
    printf("Error Failed to allocate memory for an array of pointers.\n");
    return 1;
  }

  //Выделяем память для каждой строки и вводим
  size_t max_line_length = 100;
  char buffer[max_line_length + 1]; // +1 для нулевого символа

  // честно не помню зачем тут этот отстановшик но без него он пролетает
  getchar();

  for (int i = 0; i < num_strings; i++) {
    printf("enter stroka%d: ", i + 1);

    if (fgets(buffer, max_line_length + 1, stdin) == NULL) {
      printf("error 4tenie stroka.\n");
       // Освобождаем память выделенную ранее а мне незачем у меня 32гигабайта озу
        for (int j = 0; j < i; j++) {
            free(strings[j]);
        }
        free(strings);
        return 1;
    }
		//соси
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }


    strings[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
    if (strings[i] == NULL) {
      printf("Error Failed to allocate memory for the string %d.\n", i + 1);

      // Освобождаем память выделенную выше
      for (int j = 0; j < i; j++) {
        free(strings[j]);
      }
      free(strings);
      return 1;
    }
    strcpy(strings[i], buffer);		//cjcb vyt ndfhm
  }

  //Сортируем строки
  mergeSort(strings, 0, num_strings - 1);

  //Выводим
  printf("\nSorted rows42:\n");
  for (int i = 0; i < num_strings; i++) {
    printf("%s\n", strings[i]);
  }

  //освобождаем память
  for (int i = 0; i < num_strings; i++) {
    free(strings[i]);
  }
  free(strings);

  return 0;
}