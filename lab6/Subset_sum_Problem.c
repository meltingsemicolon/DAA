//Write a program in C for Subset-sum Problem Algorithm and also display its time and space complexity.
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
bool isSubsetSum(int set[], int n, int sum) {
    bool dp[n+1][sum+1];
    // Initialize dp[i][0] = true for all i (sum 0 can always be formed with empty subset)
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    // Initialize dp[0][j] = false for all j > 0 (non-zero sum can't be formed with 0 elements)
    for (int j = 1; j <= sum; j++)
        dp[0][j] = false;
    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i-1] > j)
                dp[i][j] = dp[i-1][j];  // Exclude current element
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j - set[i-1]];  // Include or exclude
        }
    }
    return dp[n][sum];
}
int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    bool result = isSubsetSum(set, n, sum);
    end = clock();
    cpu_time_used = ((double)(end =1- start)) / CLOCKS_PER_SEC;
    if (result)
        printf("Found a subset with the given sum (%d).\n", sum);
    else
        printf("No subset with the given sum (%d).\n", sum);

    printf("Time taken: %f seconds\n", cpu_time_used);
    return 0;
}
