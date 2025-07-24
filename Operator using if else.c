#include <stdio.h>

int main()
{
    char op;
    int num1, num2;
    double ans;

    printf("Enter an operator (+, -, *, /):\n");
    scanf(" %c", &op);
    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);
    if (op == '+') {
        ans = num1 + num2;
    } else if (op == '-') {
        ans = num1 - num2;
    } else if (op == '*') {
        ans = num1 * num2;
    } else if (op == '/') {
        if (num2 != 0)
            ans = (double) num1 / num2;
        else {
            printf("Error: Division by zero\n");
            return 1;  //
        }
    } else {
        printf("Invalid operator '%c'\n", op);
        return 1;
    }

    printf("Answer = %.2lf\n", ans);
    return 0;
}
