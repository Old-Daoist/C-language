#include <stdio.h>

int main() {
    int n, k;
    long long fact = 1;
    printf("Enter a number: ");
    scanf("%d", &n);

    for (k = 1; ; k++)
        {
        fact *= k;
        if (fact * (k + 1) > n) {
            break;
        }
    }

    printf("Largest K such that K! <= %d is %d\n", n, k);

    return 0;
}

