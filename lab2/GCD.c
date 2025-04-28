// program to calculate time taken by the program to calculate the GCD of two number
#include <stdio.h>
#include <time.h>
// Function to find GCD using Euclidean algorithm recursively
int findGCD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return findGCD(b, a % b);
}

int main()
{
    clock_t start_time=clock();
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("GCD of %d and %d is %d\n", num1, num2, findGCD(num1, num2));
clock_t end_time=clock();
double execution_time=((double)end_time-start_time)/CLOCKS_PER_SEC;
printf("Time taken is (%f) second",execution_time);
    return 0;
}