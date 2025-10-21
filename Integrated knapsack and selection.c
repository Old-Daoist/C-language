#include <stdio.h>
#include <stdlib.h>

// Function to perform selection sort by ratio
void selectionSort(float profit[], float weight[], float ratio[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            if (ratio[j] > ratio[max])
                max = j;
        }
        if (max != i) {
            float temp;
            temp = ratio[i]; ratio[i] = ratio[max]; ratio[max] = temp;
            temp = profit[i]; profit[i] = profit[max]; profit[max] = temp;
            temp = weight[i]; weight[i] = weight[max]; weight[max] = temp;
        }
    }
}

// Function to perform fractional knapsack
float fractionalKnapsack(float profit[], float weight[], float ratio[], int n, float capacity, FILE *out) {
    float totalProfit = 0.0;
    float remaining = capacity;

    fprintf(out, "\nItems chosen for Knapsack:\n");
    fprintf(out, "Profit\tWeight\tUsed Weight\tFraction\n");

    for (int i = 0; i < n; i++) {
        if (remaining >= weight[i]) {
            remaining -= weight[i];
            totalProfit += profit[i];
            fprintf(out, "%.2f\t%.2f\t%.2f\t1.00 (Full)\n", profit[i], weight[i], weight[i]);
        } else {
            float fraction = remaining / weight[i];
            float usedWeight = remaining;
            totalProfit += profit[i] * fraction;
            fprintf(out, "%.2f\t%.2f\t%.2f\t%.2f (Partial)\n", profit[i] * fraction, weight[i], usedWeight, fraction);
            remaining = 0;
            break;
        }
    }
    fprintf(out, "\nTotal capacity used: %.2f / %.2f\n", capacity - remaining, capacity);
    return totalProfit;
}

int main() {
    int n;
    float M, SP;

    // Open input file
    FILE *in = fopen("D:\\SCMS\\Knapsack1.txt", "r");
    if (!in) {
        printf("Error: Cannot open input.txt\n");
        return 1;
    }

    // Read n, M, SP (no "Items" line)
    if (fscanf(in, "n = %d\nM = %f\nSP = %f\n", &n, &M, &SP) != 3) {
        printf("Error: Invalid input format\n");
        fclose(in);
        return 1;
    }

    float weight[n], cost[n], profit[n], ratio[n];

    for (int i = 0; i < n; i++) {
        if (fscanf(in, "%f %f", &weight[i], &cost[i]) != 2) {
            printf("Error: Invalid item line %d\n", i + 1);
            fclose(in);
            return 1;
        }
        profit[i] = (SP * weight[i]) - cost[i]; // profit calculation
        ratio[i] = profit[i] / weight[i];
    }
    fclose(in);

    // Open output file
    FILE *out = fopen("output.txt", "w");
    if (!out) {
        printf("Error: Cannot create output.txt\n");
        return 1;
    }

    // Display before sorting
    fprintf(out, "Before Sorting:\n");
    fprintf(out, "Item\tWeight\tCost\tProfit\tRatio\n");
    for (int i = 0; i < n; i++)
        fprintf(out, "%d\t%.2f\t%.2f\t%.2f\t%.2f\n", i + 1, weight[i], cost[i], profit[i], ratio[i]);

    // Sort by ratio
    selectionSort(profit, weight, ratio, n);

    // Display after sorting
    fprintf(out, "\nAfter Sorting by Profit/Weight Ratio:\n");
    fprintf(out, "Item\tWeight\tCost\tProfit\tRatio\n");
    for (int i = 0; i < n; i++)
        fprintf(out, "%d\t%.2f\t%.2f\t%.2f\t%.2f\n", i + 1, weight[i], cost[i], profit[i], ratio[i]);

    // Fractional Knapsack
    float maxProfit = fractionalKnapsack(profit, weight, ratio, n, M, out);
    fprintf(out, "\n Maximum profit in knapsack = %.2f\n", maxProfit);

    fclose(out);
    printf("Completed! Check output.txt for results.\n");

    return 0;
}
