/*
Write a C program that uses pointer comparison to traverse an array and find elements within a specific range. Your program should:

1. Declare an integer array named scores with 8 elements and initialize it with the values {45, 78, 92, 63, 87, 34, 91, 56}
2. Declare two pointers to integers: start_ptr and end_ptr
3. Set start_ptr to point to the first element of the array
4. Set end_ptr to point to the last element of the array using pointer arithmetic
5. Declare a pointer named current_ptr and initialize it to point to the first element
6. Use a while loop with pointer comparison (current_ptr <= end_ptr) to traverse the array
7. Inside the loop:
    - Check if the current value is between 60 and 90 (inclusive)
    - If the value is in range, print "Value [value] is in range"
    - If the value is not in range, print "Value [value] is out of range"
    - Increment current_ptr to move to the next element
8. After the loop, use pointer comparison to verify that current_ptr is now beyond the end of the array by checking if current_ptr > end_ptr
9. If the condition is true, print "Traversal complete"

Your output should display the results in the following format:
Value 45 is out of range
Value 78 is in range
Value 92 is out of range
Value 63 is in range
Value 87 is in range
Value 34 is out of range
Value 91 is out of range
Value 56 is out of range
Traversal complete

This challenge tests your understanding of pointer comparison operators in loop conditions, using pointer arithmetic to set boundary pointers, and how pointer comparison can control array traversal more elegantly than traditional counter-based loops.
*/

#include <stdio.h>

int main() {
    int scores[8] = {45, 78, 92, 63, 87, 34, 91, 56};
    int *start_ptr, *current_ptr = scores;
    int *end_ptr = scores + 7;

    while (current_ptr <= end_ptr) {
        if (*current_ptr >= 60 && *current_ptr <= 90) {
            printf("Value %d is in range\n",*current_ptr);
        } else {
            printf("Value %d is out of range\n",*current_ptr);
        }
        current_ptr++;
    }

    if (current_ptr > end_ptr) {
        printf("Traversal complete");
    }

    return 0;
}