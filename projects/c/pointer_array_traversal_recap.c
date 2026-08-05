/*
Write a C program that implements a function to calculate the sum of all elements in an integer array using pointer arithmetic and array-pointer equivalency. Your program should:

1. Create a function named calculateSum that takes two parameters:
    - A pointer to an integer (int *arr) representing the array
    - An integer (size) representing the number of elements in the array
2. Inside the calculateSum function:
    - Initialize a variable sum to 0
    - Create a pointer variable ptr and set it to point to the beginning of the array
    - Use a loop to traverse the array using pointer arithmetic
    - In each iteration, add the value pointed to by ptr to sum
    - Increment the pointer to move to the next element
    - Return the calculated sum
3. In the main function:
    - Read an integer n representing the size of the array
    - Declare an integer array of size n
    - Read n integers from input to populate the array
    - Call the calculateSum function with the array and its size
    - Print the result in the format: "Sum: [value]"

The function must use pointer arithmetic for array traversal - do not use array indexing notation like arr[i]. Instead, use pointer dereferencing and increment operations to access array elements.

For example, if the input is:
5
10 20 30 40 50

Your output should be:
Sum: 150

This challenge tests your understanding of how functions can accept arrays as pointer parameters, how to use pointer arithmetic to traverse arrays efficiently, and how array names are automatically converted to pointers when passed to functions.
*/

#include <stdio.h>

int calculateSum(int *arr, int size);

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    
    // Read array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Sum: %d", calculateSum(arr,n));
    
    return 0;
}

int calculateSum(int *arr, int size) {
    int sum = 0;
    int *ptr = arr;
    for (int i = 0; i < size; i++) {
        sum += *(ptr + i);
    }
    return sum;
}