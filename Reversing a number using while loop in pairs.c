#include <stdio.h>

int main() {
    int num, ans = 0, digit1, digit2, multiplier = 1;

    printf("Enter an integer: ");
    scanf("%d", &num);

    while (num > 9) {
        digit2 = num % 10;     // rightmost digit
        num /= 10;
        digit1 = num % 10;     // second rightmost digit
        num /= 10;

        // Append in reversed pair order
        ans += (digit2 * 10 + digit1) * multiplier;
        multiplier *= 100;
    }

    // If one digit is left (odd number of digits), add it
    if (num > 0) {
        ans += num * multiplier;
    }

    printf("Reversed in pairs = %d\n", ans);

    return 0;
}

