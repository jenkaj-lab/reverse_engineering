#include <stdio.h>

int isPrime(int num) {
    for (int i = 1; i <= num; i++) {
        if ((i > 1 && i < num) && (num % i == 0)) {
            return 0;
        }
    }

    if (num == 1) {
        return 0;
    } else {
        return 1;
    }
}

int sumOfPrimes(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int start;
    int end;
    scanf("%d",&start);
    scanf("%d",&end);


    if ((start < 0 || end < 0) || (start >= end)) {
        printf("Invalid input");
    } else {
        int sum = sumOfPrimes(start, end);
        printf("%d",sum);
    }
   
    return 0;
}