#include <stdio.h>

int main() {
    int number;
    int digits[10];
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
    do {
        digits[i] = number % 10;
        number /= 10;
        i++;
    } while (number > 0);

    for (int j = i - 1; j >= 0; j--) {
        printf("%d\n", digits[j]);
    }

    return 0;
}
