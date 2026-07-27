/*
Write a C program that demonstrates reading string input from the user using scanf and displaying it back. Your program should:

1. Declare a character array named username with 30 elements to store the user's input
2. Declare a character array named hobby with 25 elements to store another input
3. Use printf to prompt the user with the message "Enter your username:"
4. Use scanf with the %s format specifier to read the username into the username array
5. Use printf to prompt the user with the message "Enter your hobby:"
6. Use scanf with the %s format specifier to read the hobby into the hobby array
7. Print both strings using printf in the exact format shown below

The input will be provided as two separate single words (no spaces within each word).

Your output should display the results in the following format:
Enter your username:
Enter your hobby:
Hello [username], your hobby is [hobby]!

For example, if the user enters "Alice" as the username and "reading" as the hobby, the output should be:
Enter your username:
Enter your hobby:
Hello Alice, your hobby is reading!

This challenge tests your understanding of using scanf with the %s format specifier to read string input, proper character array declaration with sufficient size, and combining user input with formatted output using printf.
*/

#include <stdio.h>

int main() {
    // Declare your character arrays here
    char username[30];
    char hobby[25];
    
    // Write your code here to prompt and read input
    printf("Enter your username:\n");
    scanf("%s",username);
    printf("Enter your hobby:\n");
    scanf("%s",hobby);
    
    // Print the final output message
    printf("Hello %s, your hobby is %s!",username,hobby);
    
    return 0;
}