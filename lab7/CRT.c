//Write a program in C for Chinese Remainder Theorem Algorithm and also display its time and space complexity.
#include <stdio.h>
#include <time.h>
int gcd_extended(int a, int b, int *x, int *y) 
{
    if (b == 0) 
    {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int gcd = gcd_extended(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}
int modular_inverse(int a, int m) 
{
    int x, y;
    int g = gcd_extended(a, m, &x, &y);
    if (g != 1) 
    {
        return -1;
    }
    return (x % m + m) % m;
}
int chinese_remainder_theorem(int num[], int rem[], int n) 
{
    int product = 1; 
    for (int i = 0; i < n; i++) 
    {
        product *= num[i];
    }
    int result = 0;
    for (int i = 0; i < n; i++) 
    {
        int partial_product = product / num[i];
        int inverse = modular_inverse(partial_product, num[i]);
        result += rem[i] * partial_product * inverse;
    }
    return result % product;
}
int main() 
{
    int n; 
    printf("Enter the number of congruences: ");
    scanf("%d", &n);
    int num[n], rem[n];
    printf("Enter the moduli and remainders (num[i] rem[i]):\n");
    for (int i = 0; i < n; i++) 
    {
        printf("For congruence %d: ", i + 1);
        scanf("%d %d", &num[i], &rem[i]);
    }
    int iterations = 1000000;
    clock_t start = clock();
    int result;
    for (int i = 0; i < iterations; i++) 
    {
        result = chinese_remainder_theorem(num, rem, n);
    }
    clock_t end = clock(); 
    double total_time = (double)(end - start) / CLOCKS_PER_SEC;
    double average_time = total_time / iterations; 
    size_t space_complexity = sizeof(int) * (2 * n + 10);
    printf("The solution is x = %d\n", result);
    printf("Time complexity for %d iterations: %.10f seconds\n", iterations, total_time);
    printf("Average time per iteration: %.10f seconds\n", average_time);
    printf("Space complexity: %zu bytes\n", space_complexity);
    return 0;
}