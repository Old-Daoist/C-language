#include <stdio.h>

int main() {
    int num1, num2, num3;

    printf("Enter three integers to compare : ");
    scanf("%d %d %d", &num1, &num2, &num3);
    if (num1 > num2 && num1 > num3) {
        printf("The largest number is: %d\n", num1);
    }
    else if (num2 > num1 && num2 > num3) {
        printf("The largest number is: %d\n", num2);
    }
    else if (num3 > num1 && num3 > num2) {
        printf("The largest number is: %d\n", num3);
    }
    //for equal code num 3
    else if (num3 == num1 && num3 > num2) {
        printf("The two largest equal number is: %d\n", num3);
    }
    else if (num3 == num2 && num3 > num1) {
        printf("The two largest equal number is: %d\n", num3);
    }

    //Num 2
     else if (num2 == num3 && num2 > num1) {
        printf("The two largest equal number is: %d\n", num2);
    }
    else if (num2 == num1 && num2 > num3) {
        printf("The two largest equal number is: %d\n", num2);
    }


    //num 1
     else if (num1 == num2 && num1 > num3) {
        printf("The two largest equal number is: %d\n", num1);
    }
    else if (num1 == num3 && num1 > num2) {
        printf("The two largest equal number is: %d\n", num1);
    }
    // for all three equal
    else {
        printf("The entered integers are all equal\n ");
    }

    return 0;
}
