#include <stdio.h>

int main() {
    char name[50];
    int age;

    printf("Please enter your name below:\n");
    scanf("%s", name);

    printf("Please enter your age below:\n");
    scanf("%d", &age);

    printf("Your name is %s and your age is %d\n", name, age);

    return 0;
}
