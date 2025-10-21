#include <stdio.h>

// Function to perform selection
void selectionSort(float value[], float weight[], float ratio[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            if (ratio[j] > ratio[max])
                max = j;
        }

        if (max != i) {
            float temp;

            temp = ratio[i]; ratio[i] = ratio[max]; ratio[max] = temp;
            temp = value[i]; value[i] = value[max]; value[max] = temp;
            temp = weight[i]; weight[i] = weight[max]; weight[max] = temp;
        }
    }
}

// Function to perform fractional knapsack
float fractionalKnapsack(float value[], float weight[], float ratio[], int n, float capacity) {
    float totalValue = 0.0;
    float remaining = capacity;

    printf("\nItems chosen:\n");
    printf("Value\tWeight\tTaken\n");

    for (int i = 0; i < n; i++) {
        if (remaining >= weight[i]) {
            remaining -= weight[i];
            totalValue += value[i];
            printf("%.2f\t%.2f\t1.00 (Full)\n", value[i], weight[i]);
        } else {
            float fraction = remaining / weight[i];
            totalValue += value[i] * fraction;
            printf("%.2f\t%.2f\t%.2f (Partial)\n", value[i], weight[i], fraction);
            break;
        }
    }
    return totalValue;
}

int main() {
    int n;
    printf("Enter number of items: ");
    scanf("%d", &n);

    float value[n], weight[n], ratio[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%f %f", &value[i], &weight[i]);
        ratio[i] = value[i] / weight[i];
    }
    //To compare the values
    printf("\nBefore Sorting (value/weight):\n");
    printf("--------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("Item %d -> Value: %.2f, Weight: %.2f, Ratio: %.2f\n", i + 1, value[i], weight[i], ratio[i]);

    // Sort by ratio using selection sort
    selectionSort(value, weight, ratio, n);

    // Display after sorting
    printf("\nAfter Sorting (by ratio):\n");
    printf("--------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("Item %d -> Value: %.2f, Weight: %.2f, Ratio: %.2f\n", i + 1, value[i], weight[i], ratio[i]);

    float capacity;
    printf("\nEnter knapsack capacity: ");
    scanf("%f", &capacity);

    float maxValue = fractionalKnapsack(value, weight, ratio, n, capacity);
    printf("\nMaximum value in knapsack = %.2f\n", maxValue);

    return 0;
}
