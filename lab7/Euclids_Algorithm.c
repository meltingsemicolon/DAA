// Write a program in C for Euclid’s Algorithm and also display its time and space complexity.
#include <stdio.h>
#include <time.h>
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    int num1, num2;
    printf("Enter two integers: ");
    if (scanf("%d %d", &num1, &num2) !=2 || (num1,num2)<= 0)
    {
        printf("Invalid input.\n");
        return 1;
    }
    clock_t start = clock();
    for (int i = 0; i < ((num1 > num2) ? num1 : num2); i++)
    {
        gcd(num1, num2);
    }
    clock_t end = clock();
    printf("GCD of %d and %d is: %d\n", num1, num2, gcd(num1, num2));
    printf("Time taken %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}