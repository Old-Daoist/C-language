#include <stdio.h>

int main() {
    int n, i;
    int *arr;
    int left, right;
    int flag = 1;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    left = 0;
    right = n - 1;

    while (left < right) {
        if (arr[left] != arr[right]) {
            flag = 0;
            break;
        }
        left++;
        right--;
    }
    if(flag == 1)
        printf("The array is a palindrome.\n");
    else
        printf("The array is NOT a palindrome.\n");
        free(arr);
        return 0;
}
