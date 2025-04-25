// progarm to calculate the time taken to complete execution for finding factorial of a number.
#include <stdio.h>
#include <time.h>
int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}
int main()
{
    clock_t start_time = clock();
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("the factorial is: %d\n", fact(n));
    clock_t end_time = clock();
    double execution_time = ((double)end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time taken to execute is (%f) second ", execution_time);
    return 0;
}