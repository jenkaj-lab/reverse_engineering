#include <stdio.h>

int main() {
    int value1 = 0x21;
    int value2 = 0x66;

    printf("Enter your number : ");
    int input = scanf("%d", &value1);

    if (input == value1) {
        input = printf("Enter the Secret Key : ");
        
        if (input == value2) {
            printf("Congratulations, you have completed the");
        } 
    }
}