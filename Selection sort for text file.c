#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float weight;
    float cost;
    float profit;
    float ratio;
} Item;

int main() {
    int n;
    float M, SP;

    FILE *in = fopen("D:\\SCMS\\Knapsack1.txt", "r");
    if (!in) {
        printf("Error: Cannot open file, Please try again\n");
        return 1;
    }

    // Read first three lines with '=' signs
    if (fscanf(in, "n = %d\nM = %f\nSP = %f\n", &n, &M, &SP) != 3) {
        printf("Error: Invalid file format for n, M, SP\n");
        fclose(in);
        return 1;
    }

    Item items[n];

    // Read item lines: weight and cost
    for (int i = 0; i < n; i++) {
        if (fscanf(in, "%f %f", &items[i].weight, &items[i].cost) != 2) {
            printf("Error: Invalid item line %d\n", i + 1);
            fclose(in);
            return 1;
        }
        items[i].profit = (SP * items[i].weight) - items[i].cost;
        items[i].ratio = items[i].profit / items[i].weight;
    }

    fclose(in);

    // Selection sort by ratio descending
    for (int i = 0; i < n - 1; i++) {
        int max = i;
        for (int j = i + 1; j < n; j++) {
            if (items[j].ratio > items[max].ratio)
                max = j;
        }
        if (max != i) {
            Item temp = items[i];
            items[i] = items[max];
            items[max] = temp;
        }
    }

    // Print sorted items to console
    printf("Weight\tCost\tProfit\tRatio\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f\t%.2f\t%.2f\t%.2f\n",
               items[i].weight, items[i].cost, items[i].profit, items[i].ratio);
    }

    // Write sorted items to file
    FILE *out = fopen("sorted.txt", "w");
    if (!out) {
        printf("Error: Cannot create sorted.txt\n");
        return 1;
    }

    fprintf(out, "n = %d\nM = %.2f\nSP = %.2f\n", n, M, SP);
    for (int i = 0; i < n; i++) {
        fprintf(out, "%.2f %.2f %.2f %.2f\n",
                items[i].weight, items[i].cost, items[i].profit, items[i].ratio);
    }

    fclose(out);

    printf("✅ Sorted and saved to sorted.txt\n");

    return 0;
}
