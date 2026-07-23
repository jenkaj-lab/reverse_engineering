#include <stdio.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
void calculate(int a, int b, char operation);

int main() {
    int a, b;
    char operation;
    scanf("Enter number 1: %d", &a);
    scanf("Enter number 2: %d", &b);
    scanf("Enter operation: %c", &operation);
    
    calculate(a,b,operation);
    return 0;
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

void calculate(int a, int b, char operation) {
    switch (operation) {
        case '+':
            printf("%d", add(a,b));
            break;
        case '-':
            printf("%d", subtract(a,b));
            break;
        case '*':
            printf("%d", multiply(a,b));
            break;
        case '/':
            if (b == 0) {
                printf("Invalid input: Cannot divide by 0");
                break;
            }
            printf("%d", divide(a,b));
            break;
        default:
            printf("Invalid input");
    }
}