#include <stdio.h>
#include <time.h>

// Function to perform sequential search
int sequentialSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i; // Return the index of the target if found
    }
    return -1; // Return -1 if target is not found in the array
}

// Utility function to print array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver code
int main()
{
    clock_t start = clock();
    int arr[] = {2, 5, 9, 10, 18, 23, 30,67,89,32,91,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 18;

    int result = sequentialSearch(arr, n, target);
    if (result != -1)
        printf("Element %d is present at index %d\n", target, result);
    else
        printf("Element %d is not present in the array\n", target);

        clock_t end=clock();
        double execution_time = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken is (%f) second", execution_time);
    return 0;

}