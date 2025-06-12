#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
            swap(&arr[i], &arr[minIndex]);
    }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    clock_t start =clock();
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array is \n");
    printArray(arr, n);
    selectionSort(arr, n);
    printf("Sorted array is \n");
    printArray(arr, n);
    clock_t end = clock();
    double execution_time = (2*(double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken is (%f) second", execution_time);
    return 0;
}