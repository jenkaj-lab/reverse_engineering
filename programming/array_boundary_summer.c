/*
Creates a function called processMatrix that takes the matrix and its size as parameters and doing the following:

Calculates the sum of all elements in the matrix
Calculates the sum of diagonal elements (both main and anti-diagonal)
print the following information with appropriate labels:

“Sum of all elements: [value]”
“Sum of main diagonal: [value]”
"Sum of anti-diagonal: [value]"
*/

#include <stdio.h>

void processMatrix(int matrix[][3], int size) {
    // Write your code here
    int total_sum, main_diagonal_sum, anti_diagonal_sum;

    for (int i = 0; i < size; i ++) {
        main_diagonal_sum += matrix[i][i];
        for (int j = 0; j < size; j++) {
            total_sum += matrix[i][j];
        }
    }

    for (int i = size-1; i >= 0; i--) {
        anti_diagonal_sum += matrix[i][i];
    }
    
    printf("Sum of all elements: %d\n", total_sum);
    printf("Sum of main diagonal: %d\n", main_diagonal_sum);
    printf("Sum of anti-diagonal: %d\n", anti_diagonal_sum);

}

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    processMatrix(matrix, 3);
    
    return 0;
}