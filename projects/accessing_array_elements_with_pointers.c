/*
Write a C program that demonstrates accessing array elements using pointer notation instead of traditional array indexing. Your program should:

1. Declare an integer array named values with 6 elements and initialize it with the values {5, 15, 25, 35, 45, 55}
2. Use a for loop to iterate through all elements of the array
3. Inside the loop, use pointer notation *(values + i) to access each element (do not use bracket notation like values[i])
4. Print each element using the pointer notation access method
5. After the loop, demonstrate the equivalence by printing the third element (index 2) using both methods:
    - First using pointer notation: *(values + 2)
    - Then using traditional array notation: values[2]

Your output should display the results in the following format:
Element 0: 5
Element 1: 15
Element 2: 25
Element 3: 35
Element 4: 45
Element 5: 55
Third element via pointer: 25
Third element via array: 25

This challenge tests your understanding of the equivalence between array[i] and *(array + i), demonstrating how pointer arithmetic allows you to access array elements using memory address calculations instead of traditional indexing.
*/

#include <stdio.h>

int main() {
    // Declare and initialize the array 'values' with 6 elements
    int values[] = {5, 15, 25, 35, 45, 55};
    int length_of_array = 6;

    // Use a for loop to print each element using pointer notation *(values + i)
    for (int i = 0; i < length_of_array; i++) {
        printf("Element %d: %d\n",i,*(values + i));
    }

    // After the loop, print the third element using both pointer and array notation
    printf("Third element via pointer: %d\n",*(values + 2));
    printf("Third element via array: %d\n",values[2]);
    
    return 0;
}