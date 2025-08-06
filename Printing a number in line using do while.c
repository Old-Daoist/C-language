#include <stdio.h>

int main() {
    char number[100];
    int i = 0;

    printf("Enter an integer: ");
    scanf("%s", number);

    // If the number is negative, print '-' and start from next character
    if (number[0] == '-') {
        printf("-\n");
        i = 1;
    }

    // Print each digit using do-while
    do {
        printf("%c\n", number[i]);
        i++;
    } while (number[i] != '\0');

    return 0;
}
