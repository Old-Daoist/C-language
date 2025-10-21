#include <stdio.h>

int main() {
    int n, k = 1;
    long long ans = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    while (ans * (k + 1) <= n)
    {
        k++;
        ans *= k;
    }

    printf("Largest K such that K! <= %d is %d\n", n, k);

    return 0;
}
