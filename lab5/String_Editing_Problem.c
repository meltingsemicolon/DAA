//Write a program in C for String Editing Algorithm and also display its time and space complexity.
#include <stdio.h>
#include <string.h>
#include <time.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MIN3(a, b, c) (MIN(MIN(a, b), c))
int editDistance(char str1[], char str2[]) {
    int m = strlen(str1);
    int n = strlen(str2);
    int dp[m+1][n+1];
    // Fill dp[][] in bottom-up manner
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // If first string is empty, insert all characters of second
            if (i == 0)
                dp[i][j] = j;
            // If second string is empty, remove all characters of first
            else if (j == 0)
                dp[i][j] = i;
            // If last characters are same, ignore last and recur
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            // If last characters are different, consider all 3 operations
            else
                dp[i][j] = 1 + MIN3(dp[i][j-1],   // Insert
                                    dp[i-1][j],   // Remove
                                    dp[i-1][j-1]); // Replace
        }
    }
    return dp[m][n];
}
int main() {
    char str1[] = "sunday";
    char str2[] = "saturday";
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    int distance = editDistance(str1, str2);
    end = clock();
    cpu_time_used = ((double)(end=12-start)) / CLOCKS_PER_SEC;
    printf("Edit Distance between \"%s\" and \"%s\" = %d\n", str1, str2, distance);
    printf("Time taken: %f seconds\n", cpu_time_used);
    return 0;
}
