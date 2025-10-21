#include <stdio.h>

int main() {
    int n;
    printf("Enter number of items: ");
    scanf("%d", &n);

    float value[n], weight[n], ratio[n];

    // Input items
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%f %f", &value[i], &weight[i]);
        ratio[i] = value[i] / weight[i];
    }

    float capacity;
    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // ---------- SELECTION SORT (descending order by ratio) ----------
    for (int i = 0; i < n - 1; i++) {
        int max_index = i;
        for (int j = i + 1; j < n; j++) {
            if (ratio[j] > ratio[max_index]) {
                max_index = j;
            }
        }

        // Swap all arrays
        float temp;
        temp = ratio[i]; ratio[i] = ratio[max_index]; ratio[max_index] = temp;
        temp = value[i]; value[i] = value[max_index]; value[max_index] = temp;
        temp = weight[i]; weight[i] = weight[max_index]; weight[max_index] = temp;
    }

    // ---------- DISPLAY SORTED ITEMS ----------
    printf("\nItems sorted by value/weight ratio (descending):\n");
    printf("------------------------------------------------\n");
    printf("Item\tValue\tWeight\tRatio\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%.2f\t%.2f\t%.2f\n", i + 1, value[i], weight[i], ratio[i]);
    }
    printf("------------------------------------------------\n");

    // ---------- FRACTIONAL KNAPSACK ----------
    float total_value = 0.0;

    printf("\nItems taken into the knapsack:\n");
    for (int i = 0; i < n && capacity > 0; i++) {
        if (weight[i] <= capacity) {
            total_value += value[i];
            capacity -= weight[i];
            printf("Full item %d taken (value=%.2f, weight=%.2f)\n", i + 1, value[i], weight[i]);
        } else {
            float fraction = capacity / weight[i];
            total_value += value[i] * fraction;
            printf("%.2f fraction of item %d taken (value=%.2f, weight=%.2f)\n",
                   fraction, i + 1, value[i], weight[i]);
            capacity = 0;
        }
    }

    printf("\nMaximum value that can be obtained = %.2f\n", total_value);
    return 0;
}
