#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>

#define venom.h
#define ERROR_VALUE FLT_MAX

float enter_only_num(){
	float num1;
	if(scanf("%f", &num1)==1){
		return num1;
	}else return ERROR_VALUE;
}

int main() {
	float number1, number2, number3;
	
	printf("Enter 1 number: ");
	number1 = enter_only_num();
	if(number1==ERROR_VALUE){
		printf("Error Value");
		return 0;
	}
	
	printf("Enter 2 number: ");
	number2 = enter_only_num();
	if(number2==ERROR_VALUE){
		printf("Error Value");
		return 0;
	}
	
	printf("Enter 3 number: ");
	number3 = enter_only_num();
	if(number3==ERROR_VALUE){
		printf("Error Value");
		return 0;
	}
	
	fflush(stdin);
	char variant;
	printf("Select operation (+ - * /) : ");
	variant = getchar();
	
	float result;
	switch(variant){
		case '+':
			result=number1+number2+number3;
			printf("Result: %.0f", result);
			break;
		case '-':
			result=number1-number2-number3;
			printf("Result: %.0f", result);
			break;
		case '*':
			result=number1*number2*number3;
			printf("Result: %.0f", result);
			break;
		case '/':
			if(number2==0||number3==0){
				printf("you can't divide by 0");
				return 0;
			}
			result=number1/number2/number3;
			printf("Result: %.2f", result);
			break;
	}
	
	return 0;
}


