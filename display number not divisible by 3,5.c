#include <stdio.h>

int main() {
    int n, i;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Numbers from 1 to %d not divisible by 3 and 5 are:\n", n);
    for (i = 1; i <= n; i++) {
        if (i % 3 != 0 && i % 5 != 0) {
            printf("%d ", i);
        }
    }

    return 0;
}
