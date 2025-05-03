#include <stdio.h>
#include <time.h>
// Recursive binary search function
int recursiveBinarySearch(int arr[], int left, int right, int target)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        // If the target is present at the middle itself
        if (arr[mid] == target)
            return mid;

        // If the target is smaller than mid, then it can only be present in the left subarray
        if (arr[mid] > target)
            return recursiveBinarySearch(arr, left, mid - 1, target);

        // Else the target can only be present in the right subarray
        return recursiveBinarySearch(arr, mid + 1, right, target);
    }
    // If the target is not present in the array
    return -1;
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
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 23, 14, 15, 16, 17, 18, 19, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 19;
    // Perform recursive binary search
    int recursiveResult = recursiveBinarySearch(arr, 0, n - 1, target);
    if (recursiveResult != -1)
        printf("Recursive Binary Search: Element %d is present at index %d\n", target, recursiveResult);
    else
        printf("Recursive Binary Search: Element %d is not present in array\n", target);
    clock_t end = clock();
    double execution_time = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken is (%f) second", execution_time);
    return 0;
}
