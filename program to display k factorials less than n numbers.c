#include <stdio.h>

int main() {
    int n, k = 1;
    long long fact = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Factorials less than or equal to %d:\n", n);
    printf("%d! = %lld\n", k, fact);

    while (fact * (k + 1) <= n)
    {
        k++;
        fact *= k;
        printf("%d! = %lld\n", k, fact);
    }

    printf("\nLargest K such that K! <= %d is %d\n", n, k);

    return 0;
}
