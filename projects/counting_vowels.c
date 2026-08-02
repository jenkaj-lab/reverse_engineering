#include <stdio.h>
#include <string.h>

int check_if_vowel(char *arr){
    char lowercase_vowels[] = "aeiou";
    char uppercase_vowels[] = "AEIOU";
    int number_of_vowels = 5;
    int vowel_count = 0;

    for (int i = 0; i < strlen(arr); i++) {
        for (int j = 0; j < 5; j++) {
            if ((arr[i] == lowercase_vowels[j]) || (arr[i] == uppercase_vowels[j])) {
                vowel_count++;
            }
        }
    }
    return vowel_count;
}

int main() {
    // 1. Print the prompt message
    printf("Enter a sentence: \n");
    
    // 2. Declare a character array named 'sentence' with 200 elements
    char sentence[200];

    // 3. Read input using scanf with %s format specifier
    scanf("%199s",sentence);

    // 4. Print the entered word and its character count, length, and vowel count
    printf("You entered: %s\nCharacter count: %d\nLength: %d\nVowel count: %d",sentence,strlen(sentence),strlen(sentence),check_if_vowel(sentence));

    return 0;
}