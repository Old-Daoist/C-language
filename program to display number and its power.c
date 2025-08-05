#include <stdio.h>

int main() {
    int base, exp;
    long long result = 1;
    int i = 0;
    printf("Enter the base number: ");
    scanf("%d", &base);

    printf("Enter the exponent (power): ");
    scanf("%d", &exp);

    while (i < exp) {
        result *= base;
        i++;
    }
    printf("%d raised to the power of %d is %lld\n", base, exp, result);

    return 0;
}
