// Write a program in C for Miller-Rabin Randomized Primility Test Algorithm and also display its time and space complexity.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long long modular_exponentiation(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}
int miller_test(long long d, long long n)
{
    long long a = 2 + rand() % (n - 4);
    long long x = modular_exponentiation(a, d, n);
    if (x == 1 || x == n - 1)
    {
        return 1;
    }
    while (d != n - 1)
    {
        x = (x * x) % n;
        d *= 2;
        if (x == 1)
        {
            return 0;
        }
        if (x == n - 1)
        {
            return 1;
        }
    }
    return 0;
}
int is_prime(long long n, int k)
{
    if (n <= 1 || n == 4)
    {
        return 0;
    }
    if (n <= 3)
    {
        return 1;
    }
    long long d = n - 1;
    while (d % 2 == 0)
    {
        d /= 2;
    }
    for (int i = 0; i < k; i++)
    {
        if (!miller_test(d, n))
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    long long n;
    int k = 5;
    int iterations = 1000000;
    printf("Enter a number to check for primality: ");
    scanf("%lld", &n);
    clock_t start = clock();
    for (int i = 0; i < iterations; i++)
    {
        is_prime(n, k);
    }
    clock_t end = clock();
    double total_time = (double)(end - start) / CLOCKS_PER_SEC;
    double average_time = total_time / iterations;
    size_t space_complexity = sizeof(long long) * 5 + sizeof(int) * 2;
    if (is_prime(n, k))
    {
        printf("%lld is probably prime.\n", n);
    }
    else
    {
        printf("%lld is composite.\n", n);
    }
    printf("Time complexity for %d iterations: %.10f seconds\n", iterations, total_time);
    printf("Average time per iteration: %.10f seconds\n", average_time);
    printf("Space complexity: %zu bytes\n", space_complexity);
    return 0;
}