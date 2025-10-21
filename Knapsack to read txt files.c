#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int readData(const char *filename, int *n, float *M, float **value, float **weight);
void selectionSort(float *value, float *weight, float *ratio, int n);
float fractionalKnapsack(float *value, float *weight, float *ratio, int n, float M);

int main() {
    int n;
    float M;
    float *value = NULL;
    float *weight = NULL;

    // Read data from file
    if (!readData("items.txt", &n, &M, &value, &weight)) {
        printf("Error: Could not read data properly.\n");
        return 1;
    }

    float ratio[n];
    for (int i = 0; i < n; i++)
        ratio[i] = value[i] / weight[i];

    // Sort using selection sort
    selectionSort(value, weight, ratio, n);

    // Compute maximum value
    float maxValue = fractionalKnapsack(value, weight, ratio, n, M);

    printf("\nKnapsack capacity: %.2f\n", M);
    printf("Maximum value in knapsack = %.2f\n", maxValue);

    free(value);
    free(weight);
    return 0;
}

// Function to read data from file
int readData(const char *filename, int *n, float *M, float **value, float **weight) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) return 0;

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "n=", 2) == 0) {
            sscanf(line, "n=%d", n);
        } else if (strncmp(line, "M=", 2) == 0) {
            sscanf(line, "M=%f", M);
        } else if (strncmp(line, "value=", 6) == 0) {
            *value = (float *)malloc((*n) * sizeof(float));
            char *token = strtok(line + 6, ",");
            int i = 0;
            while (token && i < *n) {
                (*value)[i++] = atof(token);
                token = strtok(NULL, ",");
            }
        } else if (strncmp(line, "weight=", 7) == 0) {
            *weight = (float *)malloc((*n) * sizeof(float));
            char *token = strtok(line + 7, ",");
            int i = 0;
            while (token && i < *n) {
                (*weight)[i++] = atof(token);
                token = strtok(NULL, ",");
            }
        }
    }
    fclose(file);

    if (*n == 0 || *M == 0 || *value == NULL || *weight == NULL)
        return 0;
    return 1;
}

// Selection sort function
void selectionSort(float *value, float *weight, float *ratio, int n) {
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

// Fractional knapsack function
float fractionalKnapsack(float *value, float *weight, float *ratio, int n, float M) {
    float totalValue = 0.0;
    float remaining = M;

    for (int i = 0; i < n; i++) {
        if (remaining >= weight[i]) {
            remaining -= weight[i];
            totalValue += value[i];
        } else {
            totalValue += ratio[i] * remaining;
            break;
        }
    }
    return totalValue;
}
