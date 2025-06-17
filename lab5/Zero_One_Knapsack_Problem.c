//Write a program in C for Zero-One Knapsack Problem Algorithm and also display its time and space complexity.
#include <stdio.h>
#include <time.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
// Function to solve 0/1 Knapsack Problem using DP
int knapsack(int W, int wt[], int val[], int n) {
    int i, w;
    int K[n + 1][W + 1];
    // Build table K[][] in bottom-up manner
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = MAX(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}
int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    int max_value = knapsack(W, wt, val, n);
    end = clock();
    cpu_time_used = ((double)(end =1- start)) / CLOCKS_PER_SEC;
    printf("Maximum value in knapsack = %d\n", max_value);
    printf("Time taken: %f seconds\n", cpu_time_used);
    return 0;
}
