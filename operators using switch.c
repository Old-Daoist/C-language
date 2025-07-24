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

    switch (op)
    {
        case '+':
            ans = num1 + num2;
            printf("Answer = %.2lf\n", ans);
            break;

        case '-':
            ans = num1 - num2;
            printf("Answer = %.2lf\n", ans);
            break;

        case '*':
            ans = num1 * num2;
            printf("Answer = %.2lf\n", ans);
            break;

        case '/':
            if (num2 != 0) {
                ans = (double)num1 / num2;
                printf("Answer = %.2lf\n", ans);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;

        default:
            printf("Invalid operator '%c'\n", op);
    }

    return 0;
}
