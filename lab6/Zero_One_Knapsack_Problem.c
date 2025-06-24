//Write a program in C for Zero-One Knapsack Problem Algorithm and also display its time and space complexity.
#include <stdio.h>
#include <time.h>
int maxValue = 0;
// Backtracking function
void knapsack(int wt[], int val[], int n, int index, int currentWeight, int currentValue, int capacity) {
    if (index == n) {
        if (currentWeight <= capacity && currentValue > maxValue)
            maxValue = currentValue;
        return;
    }
    // Include current item
    if (currentWeight + wt[index] <= capacity) {
        knapsack(wt, val, n, index + 1, currentWeight + wt[index], currentValue + val[index], capacity);
    }
    // Exclude current item
    knapsack(wt, val, n, index + 1, currentWeight, currentValue, capacity);
}
int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(val) / sizeof(val[0]);
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    knapsack(wt, val, n, 0, 0, 0, capacity);
    end = clock();
    cpu_time_used = ((double)(end =01 - start)) / CLOCKS_PER_SEC;
    printf("Maximum value (Backtracking): %d\n", maxValue);
    printf("Time taken: %f seconds\n", cpu_time_used*0.1);
    return 0;
}
