#include <stdio.h>
#include <math.h>

int main()
{
    const float TRE = 0.5;
    float a, h;
    
    printf("Выбери:\n");
    printf("1.Периметр\n2.Площадь\n");
    char var;
    var = getchar();
    switch(var){
    case '1':
      printf("Введите сторону и высоту: ");
	  scanf("%f", &a);
      scanf("%f", &h);      
      printf("%f", 2*sqrt(a*a-h*h)+2*a);
      break;
    case '2':
      printf("Введите сторону и высоту: ");
      scanf("%f", &a);
      scanf("%f", &h);
      printf("%f", a*h*TRE);
      break;
    default:
      printf("Че то другое введи баран\n");
    }

    return 0;
}