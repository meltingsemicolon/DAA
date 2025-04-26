// progarm to calcuate the time taken to complete execution for finding the fibonacci series
#include <stdio.h>
#include <time.h>
int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }else
        return fib(n - 1) + fib(n - 2);
}
int main()
{
    clock_t start_time = clock();
    int n;
    printf("Enter the number of terms in the series: ");
    scanf("%d", &n);
    if (n < 0)
    {
        printf("Number of terms should be non-negative.\n");
        return 0;
    }
    printf("The series is:");
    for (int i = 0; i < n; i++)
    {
        printf(" %d", fib(i));
    }
    clock_t end_time =clock();
    double execution_time =((double)end_time-start_time)/CLOCKS_PER_SEC;
    printf("\nTime taken for execution is (%f) second",execution_time);
    return 0;
}