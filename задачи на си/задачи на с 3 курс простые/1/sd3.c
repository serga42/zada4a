#include<stdio.h>
#include<conio.h>
#include <math.h>
int main()
{
  float a,b;
  char var;
  int a2;
  int b2;
  while(1){
      printf("\tКалькультр\n\n");
      M:
  printf("Введи 2 числа:");
  scanf("%f %f",&a,&b);
  printf("Выбери:\n 1.Сложение\n 2.Уменьшение\n 3.умножение\n 4.деление\n 5.остаток от деления\n");
  printf(" 6.Возведение в степеь\n 7.назад\n 8.выход\n");
var = getchar();
  switch(var)
  {
    case '1':
      printf("Сумма %.0f и %.0f это %.0f\n",a,b,(a+b));
      break;
     case '2':
      printf("Умнеьшение %.0f и %.0f это %.0f\n",a,b,a-b);
      break;
    case '3':
       printf("умножение %.0f и %.0f это %.0f\n",a,b,a*b);
       break;
    case '4':
       printf("деление %.2f и %.2f это %.2f\n",a,b,a/b);
       break;
    case '5':
        a2 = (int)a;
        b2 = (int)b;
       printf("Остаток %d и %d это %d\n",a2,b2,a2%b2);
       break;
    case '6':
       printf("Степень %.0f и %.0f это %.0f\n",a,b,pow(a,b));
       break;
    case '7':
        goto M;
       break;
    case '8':
       return 0;
       break;
    default:
      printf("Че то другое введи баран\n");
  }
  }
  return 0;
}