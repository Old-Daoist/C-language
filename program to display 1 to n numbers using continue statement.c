#include <stdio.h>

int main() {
    int n, i;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Numbers from 1 to %d not ending in 5 are:\n", n);
    for (i = 1; i <= n; i++) {
        if (i % 10 == 5)
        {
            continue;
        }
        printf("%d ", i);
    }

    return 0;
}
