#include <stdio.h>

int main() {
    int a, b,c;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("The entered integers are : a = %d, b = %d\n", a, b);

    c = a;
    a=  b;
    b=  c;

    printf("The swapped integers are: a = %d, b = %d\n", a, b);

    return 0;
}
