//Write a program in C for Fractional Knapsack Problem Algorithm and also display its time and space complexity.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Item {
    int weight;
    int value;
};
// Function to compare items based on value/weight ratio (descending)
int compare(const void* a, const void* b) {
    double r1 = (double)((struct Item*)a)->value / ((struct Item*)a)->weight;
    double r2 = (double)((struct Item*)b)->value / ((struct Item*)b)->weight;
    return (r2 > r1) - (r2 < r1);  // Sort in descending order
}
double fractionalKnapsack(int capacity, struct Item items[], int n) {
    qsort(items, n, sizeof(struct Item), compare);
    double totalValue = 0.0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            // Take the whole item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take fractional part
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            break;  // Knapsack is full
        }
    }
    return totalValue;
}
int main() {
    int capacity = 50;  // Knapsack capacity
    struct Item items[] = {
        {10, 60},
        {20, 100},
        {30, 120},
    };
    int n = sizeof(items) / sizeof(items[0]);
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    double maxValue = fractionalKnapsack(capacity, items, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Maximum value in knapsack = %.2f\n", maxValue);
    printf("Time taken: %f seconds\n", cpu_time_used);
    return 0;
}
