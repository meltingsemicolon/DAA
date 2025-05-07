#include <stdio.h>
#include <time.h>
// Function to find min and max in an array
void findMinMax(int arr[], int size, int *min, int *max) {
    *min = *max = arr[0]; // Initialize min and max with the first element
    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i]; // Update min if a smaller element is found
        }
        if (arr[i] > *max) {
            *max = arr[i]; // Update max if a larger element is found
        }
    }
}
int main() {
    clock_t start=clock();
    int arr[] = {12, 5, 8, 32, 7, 19, 1, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min, max;
    findMinMax(arr, size, &min, &max);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    clock_t end = clock();
    double execution_time = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken is (%f) second", execution_time);
    return 0;
}
