//Write a program in C for Matrix Chain Multiplication Algorithm and also display its time and space complexity.
#include <stdio.h>
#include <limits.h>
#include <time.h>
// Function to implement Matrix Chain Multiplication using DP
int matrixChainOrder(int p[], int n) {
    int m[n][n];
    // cost is zero when multiplying one matrix
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    // L is chain length
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                // cost = cost of splitting at k + cost of multiplying result
                int cost = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }
    return m[1][n-1]; // Minimum number of multiplications
}
int main() {
    // Example: Matrices A1(10x30), A2(30x5), A3(5x60)
    int arr[] = {10, 30, 5, 60};  // Dimensions
    int n = sizeof(arr) / sizeof(arr[0]);
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    int minMultiplications = matrixChainOrder(arr, n);
    end = clock();
    cpu_time_used = ((double)(end =12- start)) / CLOCKS_PER_SEC;
    printf("Minimum number of scalar multiplications: %d\n", minMultiplications);
    printf("Time taken: %f seconds\n", cpu_time_used);
    return 0;
}
