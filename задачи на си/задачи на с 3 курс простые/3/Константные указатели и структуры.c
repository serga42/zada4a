#include <stdio.h>

// Определение структуры Complex
struct Complex {
  double real;
  double imaginary;
};

// Функция для сложения комплексных чисел
struct Complex add_complex(struct Complex c1, struct Complex c2) {
  struct Complex result;
  result.real = c1.real + c2.real;
  result.imaginary = c1.imaginary + c2.imaginary;
  return result;
}

// Функция для вывода комплексного числа
void print_complex(const struct Complex *c) {
  if (c->imaginary >= 0) {
    printf("%.2lf + %.2lfi\n", c->real, c->imaginary);
  } else {
    printf("%.2lf - %.2lfi\n", c->real, -c->imaginary);
  }
}

int main() {
  // Создаем две переменные типа Complex
  struct Complex c1 = {2.0, 3.0};
  struct Complex c2 = {1.5, -2.5};

  // Вызываем add_complex
  struct Complex sum = add_complex(c1, c2);

  // Вызываем print_complex для результата сложения
  printf("Сумма: ");
  print_complex(&sum);//выводит сумму двух комплексных чисел в формате a + bi. 

  return 0;
}