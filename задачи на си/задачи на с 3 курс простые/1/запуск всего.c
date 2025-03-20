#include <stdio.h>
#include <windows.h>
//#include "sex.h"

int main(){
	char variant;
	printf("enter variant:");
	variant = getchar();
	const float KM_TO_MILES = 0.62137;
    const float MILES_TO_KM = 1.60934;
    float a;
    const float TRE = 0.5;
    float h;//переменая a
    int num;
    float b;//переменная a
    int n;
    int a2;
    int b2;
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );
    
	switch(variant){
		case '1'://первая программа
    printf("vibor:\n");
    printf("1.KM in mils\n2.mils in KM:\n");
    int num;
    scanf("%d", &num);
    switch(num){
    case 1:
      printf("enter KM: ");
      scanf("%f", &a);
      printf("%f", a*KM_TO_MILES);
      break;
    case 2:
      printf("enter mils: ");
      scanf("%f", &a);
      printf("%f", a*MILES_TO_KM);
      break;
    default:
      printf("you eblan\n");
    }
			break;
			
		case '2'://вторая программа
    printf("vibor:\n");
    printf("1.perimetr\n2.ploshad\n");
    scanf("%d", &num);
    switch(num){
    case 1:
      printf("Enter the side and height: ");
      scanf("%f", &a);
      scanf("%f", &h);
      printf("%f", 2*sqrt(a*a-h*h)+2*a);
      break;
    case 2:
      printf("Enter the side and height: ");
      scanf("%f", &a);
      scanf("%f", &h);
      printf("%f", a*h*TRE);
      break;
    default:
      printf("you eblan\n");
    }
			break;
			
		case '3':
  while(1){
      printf("\tKALKYLITR\n\n");
      M:
  printf("enter 2 namber:");
  scanf("%f %f",&a,&b);
  printf("\n 1.(+)\n 2.(-)\n 3.(*)\n 4.(/)\n 5.(ostat)\n");
  printf(" 6.(a^b)\n 7.back\n 8.exit\n");
  scanf("%d",&n);
  switch(n)
  {
    case 1:
      printf("sum %.0f and %.0f this %.0f\n",a,b,(a+b));
      break;
     case 2:
      printf("(-) %.0f and %.0f this %.0f\n",a,b,a-b);
      break;
    case 3:
       printf("(*) %.0f and %.0f this %.0f\n",a,b,a*b);
       break;
    case 4:
       printf("(/) %.2f and %.2f this %.2f\n",a,b,a/b);
       break;
    case 5:
        a2 = (int)a;
        b2 = (int)b;
       printf("(%) %d and %d this %d\n",a2,b2,a2%b2);
       break;
    case 6:
       printf("(a^b) %.0f and %.0f this %.0f\n",a,b,pow(a,b));
       break;
    case 7:
       break;
    case 8:
       break;
    default:
      printf("you eblan\n");
  }
  }
			break;
				
		case '4':
			if( !CreateProcess( NULL, "sd4.exe", NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi )          
	    ) 
	    {
	        printf( "CreateProcess failed (%d).\n", GetLastError() );
	        return;
	    }
			break;
		default:
      printf("you eblan\n");
	}
	
	return 0;
} 