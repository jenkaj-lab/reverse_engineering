/*
Write a function called findAverage that calculates the average of all elements in an integer array.

The function should:

Take an integer array and its size as parameters
Calculate the sum of all elements
Divide the sum by the number of elements to get the average
Return the average as a float
After calculating the average, print the result with exactly 2 decimal places using: printf("Average: %.2f\n", average);
*/

#include <stdio.h>

// Write your findAverage function here
float findAverage (int numbers[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return sum/size;
}

int main() {
    int size;
    scanf("%d", &size);
    
    int numbers[size];
    
    // Read array elements
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }
    
    // Call your function and print the result
    float average = findAverage(numbers, size);
    printf("Average: %.2f\n", average);
    
    return 0;
}