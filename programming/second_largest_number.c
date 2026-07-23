/*
Write a function called findSecondLargest that finds the second largest element in an integer array.

Your function should:

Take an integer array and its size as parameters
Return the second largest element
Handle the special case where all elements are the same (return the same value)
Example:

For array [3, 8, 2, 10, 5], the second largest is 8
For array [7, 7, 7], the second largest is also 7
*/

#include <stdio.h>

int findSecondLargest(int numbers[], int size);

int main() {
    int size;
    scanf("%d", &size);
    
    int numbers[size];
    
    // Read array elements
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }
    
    // Call your function and print the result
    int secondLargest = findSecondLargest(numbers, size);
    printf("%d", secondLargest);
    
    return 0;
}

int findSecondLargest(int numbers[], int size) {
    int first_largest_number = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > first_largest_number) {
            first_largest_number = numbers[i];
        }
    }

    int second_largest_number = numbers[0];
    for (int i = 1; i < size; i++) {
        if ((numbers[i] > second_largest_number) && (numbers[i] < first_largest_number)) {
            second_largest_number = numbers[i];
        }
    }

    return second_largest_number;
}