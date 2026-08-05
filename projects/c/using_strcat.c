/*
Write a C program that demonstrates string concatenation using the strcat() function to build personalized messages. Your program should:

1. Read an integer n representing the number of people to process
2. For each person:
  - Read their first name from input
  - Read their last name from input
  - Create a character array named fullName with 100 elements
  - Use strcpy() to copy the first name into fullName
  - Use strcat() to append a single space " " to fullName
  - Use strcat() to append the last name to fullName
  - Create a character array named greeting with 150 elements
  - Use strcpy() to copy "Hello, " into greeting
  - Use strcat() to append the fullName to greeting
  - Use strcat() to append "! Welcome to our program." to greeting
  - Print the final greeting message
3. After processing all people, create a summary message:
  - Create a character array named summary with 100 elements
  - Use strcpy() to copy "Total people processed: " into summary
  - Convert the number n to a string and use strcat() to append it to summary
  - Print the summary message

Remember to include the <string.h> header to use the string functions.

Your output should display the results in the following format:

Hello, [FirstName LastName]! Welcome to our program.
Hello, [FirstName LastName]! Welcome to our program.
...
Total people processed: [n]

For example, if the input is:
2
John
Doe
Alice
Smith

Your output should be:
Hello, John Doe! Welcome to our program.
Hello, Alice Smith! Welcome to our program.
Total people processed: 2

This challenge tests your understanding of using strcat() to concatenate multiple strings together, combining it with strcpy() for initial string setup, and building complex strings from multiple components step by step.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Read the number of people
    int n;
    scanf("%d", &n);
    
    // Process each person and create greeting messages
    char fullName[100];
    char greeting[150]; 

    for (int i = 0; i < n; i++) {
        char firstName[20];
        char lastName[20];
        
        scanf("%19s",firstName);
        scanf("%19s",lastName);

        strcpy(fullName,firstName);
        strcat(fullName," ");
        strcat(fullName,lastName);

        strcpy(greeting, "Hello, ");
        strcat(greeting,fullName);
        strcat(greeting,"! Welcome to our program.");

        printf("%s\n",greeting);
    }

    // Then create and display the summary message
    printf("Total people processed: %d",n);

    return 0;
}
