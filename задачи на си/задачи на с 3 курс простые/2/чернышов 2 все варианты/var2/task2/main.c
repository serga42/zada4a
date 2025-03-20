#include <stdio.h>
#include <ctype.h>

void perform_operation(double* result, const char operation, double second_operand) {
    switch (operation) {
        case '+': 
            *result += second_operand;
            break;
        case '-': 
            *result -= second_operand;
            break;
        case '*': 
            *result *= second_operand;
            break;
        case '/': 
            if (second_operand == 0) {
                printf("Error: Division by zero!\n");
                break;
            }
            *result /= second_operand;
            break;
        default:
            break;
    }
}

int main() {
    double result = 0.0; 
    char operation; 
    double second_operand;

    printf("Enter the first number: ");
    if (scanf("%lf", &result) != 1) {
        printf("Invalid input for number!\n");
        return 0;
    }
    
    printf("Enter the second number: ");
    if (scanf("%lf", &second_operand) != 1) {
        printf("Invalid input for number!\n");
        return 0;
    }

    printf("Enter an operation (+, -, *, /, =): ");
    if (scanf(" %c", &operation) != 1 || !strchr("+-*/=", operation)) {
        printf("Invalid operation!\n");
        return 0;
    }
      
    perform_operation(&result, operation, second_operand);

    while (operation != '=') {
        printf("Current result: %.2f\n", result);
        printf("Enter the second number: ");
        if (scanf("%lf", &second_operand) != 1) {
            printf("Invalid input for number!\n");
            break;
        }

        printf("Enter an operation (+, -, *, /, =): ");
        if (scanf(" %c", &operation) != 1 || !strchr("+-*/=", operation)) {
            printf("Invalid operation!\n");
            break;
        }

        perform_operation(&result, operation, second_operand);

        while (getchar() != '\n');
    }
    printf("Final result: %.2f\n", result);

    return 0;
}

