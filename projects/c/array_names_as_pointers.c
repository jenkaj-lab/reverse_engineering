/*
Write a C program that demonstrates the equivalence between array names and pointers to their first elements. Your program should:

1. Declare an integer array named numbers with 4 elements and initialize it with the values {10, 20, 30, 40}
2. Declare a pointer to an integer named ptr
3. Assign the array name numbers to the pointer ptr
4. Print the address stored in numbers using printf with the %p format specifier
5. Print the address of the first element &numbers[0] using printf with the %p format specifier
6. Print the address stored in ptr using printf with the %p format specifier
7. Print the value of the first element using the array name: *numbers
8. Print the value of the first element using the pointer: *ptr

Your output should display the results in the following format:
Array name address: [address]
First element address: [address]
Pointer address: [address]
Value via array name: 10
Value via pointer: 10

This challenge demonstrates that the array name acts as a constant pointer to the first element, and that numbers, &numbers[0], and ptr all contain the same memory address when ptr is assigned the array name.
*/

#include <stdio.h>

int main() {
    // 1. Declare and initialize the array 'numbers' with {10, 20, 30, 40}
    int numbers[] = {10, 20, 30, 40};

    // 2. Declare a pointer to integer named 'ptr'
    int *ptr = NULL;

    // 3. Assign the array name to the pointer
    ptr = numbers;

    // 4. Print all the required addresses and values
    printf("Array name address: %p\n",numbers);
    printf("First element address: %p\n",numbers);
    printf("Pointer address: %p\n",ptr);
    printf("Value via array name: %d\n",*numbers);
    printf("Value via pointer: %d\n",*ptr);
    
    return 0;
}