#include <stdio.h>
#include <math.h>

// Function for factorial
int factorial(int n) {
    int i;
    int fact = 1;
    for (i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    char operator;
    int num1, num2, result;

    printf("Enter the operation in the format: number1 operator number2 (Example: 2+4)\n");
    scanf("%d %c %d", &num1, &operator, &num2);

    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("Result: %d\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Result: %d\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Result: %d\n", result);
            break;
        case '/':
            if (num2 != 0)
                printf("Result: %d\n", num1 / num2);
            else
                printf("Error: Division by zero!\n");
            break;
        case '%':
            if (num2 != 0)
                printf("Result: %d\n", num1 % num2);
            else
                printf("Error: Modulus by zero!\n");
            break;
        case '!':
            printf("Factorial of %d is: %d\n", num1, factorial(num1));
            break;
        case '^':
            printf("Result: %.0lf\n", pow(num1, num2)); // Power function
            break;
        default:
            printf("Invalid operator!\n");
            break;
    }

    return 0;
}

