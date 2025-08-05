#include <stdio.h>

int countDigits(int n) {
    if (n == 0) {
        return 1;
    }

    int count = 0;
    while (n != 0) {
        n /= 10; // Integer division removes the last digit
        count++; // Increment the count for each digit removed
    }
    return count;
}

int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);

    int digits = countDigits(number);
    printf("Number of digits: %d\n", digits);

    return 0;
}
