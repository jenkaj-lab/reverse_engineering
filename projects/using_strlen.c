/*
Write a C program that reads multiple words from input and analyzes their lengths using the strlen() function. Your program should:

1. Read an integer n representing the number of words to process
2. For each of the n words:
    - Declare a character array with 50 elements to store the word
    - Read the word using scanf
    - Use strlen() to calculate the length of the word
    - Print the word and its length in the specified format
3. After processing all words, calculate and print the total number of characters across all words
4. Find and print the length of the longest word encountered

Remember to include the <string.h> header to use the strlen() function.

Your output should display the results in the following format:
Word: [word] - Length: [length]
Word: [word] - Length: [length]
...
Total characters: [total]
Longest word length: [max_length]

For example, if the input is:
3
hello
programming
C

Your output should be:
Word: hello - Length: 5
Word: programming - Length: 11
Word: C - Length: 1
Total characters: 17
Longest word length: 11

This challenge tests your understanding of using strlen() to measure string lengths, processing multiple strings with loops, and performing calculations based on string length data.
*/

#include <stdio.h>
#include <string.h>

int main() {
    // Read the number of words
    int n;
    scanf("%d", &n);
    
    // Variables to track totals
    int total_characters = 0;
    int max_length = 0;

    for (int i = 0; i < n; i++) {
        char buffer[50];
        scanf("%s",buffer);
        int length = strlen(buffer);
        printf("Word: %s - Length: %d\n",buffer,length);
        total_characters += length;
        if (length > max_length) {
            max_length = length;
        }
    }

    // Print final results
    printf("Total characters: %d\n", total_characters);
    printf("Longest word length: %d\n", max_length);
    
    return 0;
}