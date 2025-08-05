#include <stdio.h>

int main()
{
    int num, temp, remainder, ans = 0;

    printf("Enter an integer \n");
    scanf("%d", &num);
    temp = num;// this is needed to store the org value of num before the loop
    while (num > 0)
    {
        remainder = num % 10;
        ans = ans * 10 + remainder;
        num /= 10;
    }
    printf("Given number is = %d\n", temp);
    printf("Its reverse is  = %d\n", ans);
    if (temp == ans)
        printf("Number is a palindrome \n");
    else
        printf("Number is not a palindrome \n");
}
