#include <stdio.h>

int main() {
    int value1 = 0x21;
    int value2 = 0x66;

    printf("Enter your number : ");
    int input = scanf("%d", &value1);

    if (input == 1) {
        printf("Enter the Secret Key : ");
        input = scanf("%d", &value1);
        
        if (input == 1) {
            printf("Congratulations, you have completed the...\n");
        } 
    }
}