/*
Write a C program that demonstrates creating and working with strings using manual character-by-character initialization with proper null termination. Your program should:

1. Declare a character array named name with exactly 5 elements
2. Manually initialize the name array character by character to spell "John" with proper null termination:
   - First element: 'J'
   - Second element: 'o'
   - Third element: 'h'
   - Fourth element: 'n'
   - Fifth element: '\0' (null terminator)
3. Declare a second character array named city with exactly 7 elements
4. Manually initialize the city array character by character to spell "Boston" with proper null termination:
   - Use individual character assignments for 'B', 'o', 's', 't', 'o', 'n', and '\0'
5. Print both strings using printf with the %s format specifier
6. Demonstrate what happens without null termination by creating a third character array named test with 4 elements
7. Initialize test with only the characters 'A', 'B', 'C', 'D' (no null terminator)
8. Print the test array using %s to show unpredictable output

Your output should display the results in the following format:
Name: John
City: Boston
Test without null terminator: ABCD[unpredictable characters]

This challenge tests your understanding of manual string construction, the critical importance of the null terminator '\0' in C strings, and how printf with %s relies on finding the null terminator to know where the string ends.
*/

#include <stdio.h>

int main() {
    // Declare and initialize the character arrays as specified
    char name[5] = {'J','o','h','n','\0'};
    char city[7] = {'B','o','s','t','o','n','\0'};

    printf("Name: %s\n",name);
    printf("City: %s\n",city);

    char test[4] = {'A','B','C','D'};
    printf("Test without null terminator: %s",test);
    
    return 0;
}