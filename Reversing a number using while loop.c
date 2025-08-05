#include <stdio.h>

int main() {
    int num, ans = 0, remainder;

    printf("Enter an integer: ");
    scanf("%d", &num);

    while (num > 0) {
        remainder = num % 10;
        ans = ans * 10 + remainder;
        num /= 10;
    }

    printf("Reversed Number = %d\n", ans);

    return 0;
}
