#include <stdio.h>

// Write your sumArray function here
int sumArray (int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Call the sumArray function and print the result
    printf("Sum: %d", sumArray(arr,n));
    
    return 0;
}