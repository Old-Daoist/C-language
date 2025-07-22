#include <stdio.h>

int main() {
    int num1, num2, num3;

    printf("Enter three integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    if (num1 >= num2 && num1 >= num3) {
        printf("The largest number is: %d\n", num1);
    }
    else if (num2 >= num1 && num2 >= num3) {
        printf("The largest number is: %d\n", num2);
    }
    else if (num3 >= num1 && num3 >= num2) {
        printf("The largest number is: %d\n", num3);
    }
    else {
        printf("The entered integers are equal\n ");
    }

    return 0;
}
