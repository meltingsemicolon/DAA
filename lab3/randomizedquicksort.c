#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[],int loq,int high);
// Function to generate a random index between low and high
int randomizedPartition(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low);  // Random index between low and high
    swap(&arr[randomIndex], &arr[high]);  // Swap the random pivot with the last element
    return partition(arr, low, high);
}
// Function for partitioning the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the last element as pivot
    int i = low - 1;  // Index of the smaller element
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);  // Swap elements if current is smaller than or equal to pivot
        }}
    swap(&arr[i + 1], &arr[high]);  // Place the pivot in its correct position
    return i + 1;
}
// Recursive function for randomized quick sort
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);  // Get the pivot index
        randomizedQuickSort(arr, low, pi - 1);  // Recursively sort the left subarray
        randomizedQuickSort(arr, pi + 1, high);  // Recursively sort the right subarray
    }}
int main() {
    clock_t start=clock();
    int arr[] = {12, 7, 9, 5, 3, 8, 14, 18};
    int size = sizeof(arr) / sizeof(arr[0]);
    srand(time(NULL));  // Initialize random number generator
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); }
    printf("\n");
    randomizedQuickSort(arr, 0, size - 1);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);}
    printf("\n");
    clock_t end = clock();
    double execution_time = (2*(double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken is (%f) second", execution_time);
    return 0;}
