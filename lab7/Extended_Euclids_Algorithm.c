#include <stdio.h>
#include <time.h>
void extended_gcd(int m, int b)
{
    int A1 = 1, A2 = 0, A3 = m;
    int B1 = 0, B2 = 1, B3 = b;
    int Q, T1, T2, T3;
    int steps = 0;
    printf("\nStep\tA1\tA2\tA3\tB1\tB2\tB3\n");
    printf("---------------------------------------------------------\n");
    printf("Init\t%d\t%d\t%d\t%d\t%d\t%d\n", A1, A2, A3, B1, B2, B3);
    while (B3 != 0 && B3 != 1)
    {
        Q = A3 / B3;
        T1 = A1 - Q * B1;
        T2 = A2 - Q * B2;
        T3 = A3 - Q * B3;
        A1 = B1;
        A2 = B2;
        A3 = B3;
        B1 = T1;
        B2 = T2;
        B3 = T3;
        steps++;
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", Q, A1, A2, A3, B1, B2, B3);
    }
    printf("---------------------------------------------------------\n");
    if (B3 == 0)
    {
        printf("No inverse exists (GCD ≠ 1).\n");
    }
    else if (B3 == 1)
    {
        printf("GCD(%d, %d) = %d\n", m, b, B3);
        int inverse = B2 < 0 ? B2 + m : B2;
        printf("The modular inverse of %d mod %d is: %d\n", b, m, inverse);
    }
    // Time complexity in terms of number size (not steps)
    printf("Theoretical time complexity: O(log min(%d, %d))\n", m, b);
    printf("Actual steps executed: %d\n", steps);
}
int main()
{
    int m, b;
    printf("Enter the value of m: ");
    scanf("%d", &m);
    printf("Enter the value of b: ");
    scanf("%d", &b);
    clock_t start = clock();
    extended_gcd(m, b);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    // Space complexity: we use 6 integers + a few temps
    size_t space_complexity = sizeof(int) * 10;
    printf("Execution time: %.10f seconds\n", time_taken);
    printf("Estimated space complexity: %zu bytes\n", space_complexity);
    return 0;
}
