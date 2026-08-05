/*
Write a C program that demonstrates pointer arithmetic by using pointer increment operations to traverse and process an array. Your program should:

1. Declare an integer array named data with 5 elements and initialize it with the values {12, 24, 36, 48, 60}
2. Declare a pointer to an integer named ptr and initialize it to point to the first element of the array
3. Use a for loop that runs 5 times to traverse the entire array using only pointer arithmetic
4. Inside the loop:
    - Print the current value that ptr points to using the dereference operator
    - Print the memory address stored in ptr using the %p format specifier
    - Increment the pointer using ptr++ to move to the next element
5. After the loop, reset ptr to point back to the first element of the array
6. Use pointer arithmetic to directly access and print the third element (index 2) using *(ptr + 2)
7. Use pointer arithmetic to directly access and print the last element (index 4) using *(ptr + 4)

Your output should display the results in the following format:
Value: 12, Address: [address]
Value: 24, Address: [address]
Value: 36, Address: [address]
Value: 48, Address: [address]
Value: 60, Address: [address]
Third element: 36
Last element: 60

This challenge tests your understanding of how pointer increment operations automatically move by the size of the data type, and how you can use pointer arithmetic to access array elements at specific offsets from a base pointer position.
*/

#include <stdio.h>

int main() {
    // Declare and initialize the array 'data' with values {12, 24, 36, 48, 60}
    int data[] = {12, 24, 36, 48, 60};
    int array_size = 5;

    // Declare pointer 'ptr' and initialize it to point to the first element
    int *ptr = data;

    // Use a for loop with pointer arithmetic to traverse the array
    for (int i = 0; i < array_size; i++) {
        // Print each value and address, then increment the pointer
        printf("Value: %d, Address: %p\n",*ptr,ptr);
        ptr++;
    }
    
    // Reset the pointer and use pointer arithmetic to access specific elements
    ptr = data;
    printf("Third element: %d",*(ptr+2));
    printf("Last element: %d",*(ptr+4));
    
    return 0;
}