#include <stdio.h>

int main() {
    int n;
    float M, SP;

    FILE *in = fopen("D:\\SCMS\\C++ Projects\\sorted.txt", "r");
    if (!in) {
        printf("Error: Cannot open sorted.txt\n");
        return 1;
    }
    if (fscanf(in, "n = %d\nM = %f\nSP = %f\n", &n, &M, &SP) != 3) {
        printf("Error: Invalid sorted file\n");
        fclose(in);
        return 1;
    }

    float weight[n], cost[n], profit[n], ratio[n];
    for (int i = 0; i < n; i++)
        fscanf(in, "%f %f %f %f", &weight[i], &cost[i], &profit[i], &ratio[i]);
    fclose(in);

    float remaining = M, total = 0;
    FILE *out = fopen("output.txt", "w");
    if (!out) {
        printf("Error: Cannot create output.txt\n");
        return 1;
    }

    fprintf(out, "Selected Items with weight & profit\n");
    printf("Selected Items with weight & profit\n"); // Print to console too

    for (int i = 0; i < n; i++) {
        if (remaining >= weight[i]) {
            remaining -= weight[i];
            total += profit[i];
            fprintf(out, "%.2f %.2f (Full)\n", weight[i], profit[i]);
            printf("%.2f %.2f (Full)\n", weight[i], profit[i]);
        } else {
            float frac = remaining / weight[i];
            total += profit[i] * frac;
            fprintf(out, "%.2f %.2f (Fraction %.2f)\n", weight[i], profit[i] * frac, frac);
            printf("%.2f %.2f (Fraction %.2f)\n", weight[i], profit[i] * frac, frac);
            break;
        }
    }

    fprintf(out, "\nTotal Profit %.2f\n", total);
    printf("\nTotal Profit %.2f\n", total);

    fclose(out);

    printf(" Knapsack done. Output saved to output.txt\n");
    return 0;
}
