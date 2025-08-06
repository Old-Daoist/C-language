#include <stdio.h>

int main() {
    int number;
    int digits[10]; // Supports up to 10 digits
    int i = 0;

    printf("Enter an integer: ");
    scanf("%d", &number);
    if (number == 0) {
        printf("0\n");
        return 0;
    }
    if (number < 0) {
        printf("-\n");
        number = -number;
    }
    while (number > 0) {
        digits[i] = number % 10;
        number /= 10;
        i++;
    }

    // Print in correct order
    for (int j = i - 1; j >= 0; j--) {
        printf("%d\n", digits[j]);
    }

    return 0;
}
