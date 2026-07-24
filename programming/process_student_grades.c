/*
Write a program to process student grades. Implement the following logic:

calculateAverage: Return the mean of all grades as a float.

findHighestGrade: Return the maximum integer found in the array.

determineLetterGrade: Map scores to letters:
- Between 90-100: A
- Between 80-89: B
- Between 70-79: C
- Between 60-69: D
- Below 60: F
*/

#include <stdio.h>

// Function prototypes
float calculateAverage(int grades[], int size);
int findHighestGrade(int grades[], int size);
char determineLetterGrade(int grade);

float calculateAverage(int grades[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += grades[i];
    }
    return sum/size;
}

int findHighestGrade(int grades[], int size) {
    int highest_grade = grades[0];
    for (int i = 1; i < size; i++) {
        if (grades[i] > highest_grade) {
            highest_grade = grades[i];
        }
    }
    return highest_grade;
}

char determineLetterGrade(int grade) {
    switch (grade / 10) {
        case 10:
        case 9:
            return 'A';
            break;
        case 8:
            return 'B';
            break;
        case 7:
            return 'C';
            break;
        case 6:
            return 'D';
            break;
        default:
            return 'F';
            break;
    }
}

int main() {
    int size;
    scanf("%d", &size);
    int grades[size];
    
    for (int i = 0; i < size; i++) {
        scanf("%d", &grades[i]);
    }
    
    // Calculate and display the average grade
    float average = calculateAverage(grades, size);
    printf("Average grade: %.2f\n", average);
    
    // Find and display the highest grade
    int highest = findHighestGrade(grades, size);
    printf("Highest grade: %d\n", highest);
    
    // Display letter grade for each numerical grade
    printf("\nStudent Grades:\n");
    for (int i = 0; i < size; i++) {
        char letterGrade = determineLetterGrade(grades[i]);
        printf("Student %d: %d - %c\n", i+1, grades[i], letterGrade);
    }
    
    return 0;
}