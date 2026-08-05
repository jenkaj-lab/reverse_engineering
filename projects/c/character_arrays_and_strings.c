/*
Write a C program that processes pairs of words and demonstrates all the essential string functions you've learned. Your program should:

1. Read an integer n representing the number of word pairs to process
2. For each word pair:
    - Read the first word from input
    - Read the second word from input
    - Use strlen() to calculate and print the length of each word
    - Use strcmp() to compare the two words and print whether they are identical or different
    - Create a combined string by concatenating the first word, a space, and the second word using strcpy() and strcat()
    - Print the combined string
3. After processing all pairs, find and print the pair that created the longest combined string

Remember to include the <string.h> header to use the string functions.

Your output should display the results in the following format:
Word 1: [word1] (Length: [length1])
Word 2: [word2] (Length: [length2])
Comparison: [identical/different]
Combined: [word1 word2]
Word 1: [word1] (Length: [length1])
Word 2: [word2] (Length: [length2])
Comparison: [identical/different]
Combined: [word1 word2]
...
Longest combined string: [longest_combined_string]

For example, if the input is:
3
hello
world
test
test
programming
language

Your output should be:
Word 1: hello (Length: 5)
Word 2: world (Length: 5)
Comparison: different
Combined: hello world
Word 1: test (Length: 4)
Word 2: test (Length: 4)
Comparison: identical
Combined: test test
Word 1: programming (Length: 11)
Word 2: language (Length: 8)
Comparison: different
Combined: programming language
Longest combined string: programming language

This challenge tests your understanding of combining strlen() for length calculation, strcmp() for string comparison, and strcpy() with strcat() for string concatenation in a comprehensive program that processes multiple string pairs.
*/

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    char word1[100], word2[100];
    char combined[200];
    char longest_combined[200] = "";
    
    for (int i = 0; i < n; i++) {
        // Take input and calculate lengths
        scanf("%s",word1);
        scanf("%s",word2);
        int word1_length = strlen(word1);
        int word2_length = strlen(word2);
        printf("Word 1: %s (Length: %d)\n",word1,word1_length);
        printf("Word 2: %s (Length: %d)\n",word2,word2_length);

        // Compare strings to see if identical or different
        if (strcmp(word1,word2) != 0) {
            printf("Comparison: different\n");
        } else {
            printf("Comparison: identical\n");
        }

        // Combine strings
        strcpy(combined,word1);
        strcat(combined," ");
        strcat(combined,word2);
        printf("Combined: %s\n",combined);

        // Calculate longest string combination
        if (strlen(combined) > strlen(longest_combined)) {
            strcpy(longest_combined,combined);
        }
    }
    printf("Longest combined string: %s",longest_combined);
    
    return 0;
}