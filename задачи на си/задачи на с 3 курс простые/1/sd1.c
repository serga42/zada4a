#include <stdio.h>

int main()
{
    const float KM_TO_MILES = 0.62137;
    const float MILES_TO_KM = 1.60934;
    float a;
    printf("Выбери:\n");
    printf("1.Километры в мили\n2.Мили в километры:\n");
    char var;
    var = getchar();
    switch(var){
    case '1':
      printf("Введите киллометры: ");
      scanf("%f", &a);
      printf("%f", a*KM_TO_MILES);
      break;
    case '2	':
      printf("Введите мили: ");
      scanf("%f", &a);
      printf("%f", a*MILES_TO_KM);
      break;
    default:
      printf("Че то другое введи баран\n");
    }

    return 0;
}
