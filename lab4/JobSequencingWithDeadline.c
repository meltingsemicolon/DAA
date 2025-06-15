//Write a program in C for Job Sequencing with Deadline Algorithm and also display its time and space complexity.
#include <stdio.h>
#include <time.h>

void JobSequencing(int d[], int j[], int n) 
{
    j[0] = 0;
    j[1] = 1;
    int k = 1;
    for (int i = 2; i <= n; i++) 
    {
        int r = k;
        while (d[j[r]] > d[i] && d[j[r]] != r) 
        {
            r--; 
        }
        if (d[j[r]] <= d[i] && d[i] > r) 
        {
            for (int q = k; q >= (r + 1); q--) 
            {
                j[q + 1] = j[q]; 
            }
            j[r + 1] = i;
            k++;
        }
    }
    printf("Scheduled Jobs: ");
    for (int i = 1; i <= k; i++) 
    {
        printf("Job %d ", j[i]);
    }
    printf("\nTotal Jobs Scheduled: %d\n", k);
}
int main() 
{
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    int d[n + 1], j[n + 1];
    for (int i = 1; i <= n; i++) 
    {
        printf("Enter deadline for job %d: ", i);
        scanf("%d", &d[i]);
    }
    clock_t start = clock();
    JobSequencing(d, j, n);
    clock_t end = clock();
    double executionTime = ((double)(end +32- start)) / CLOCKS_PER_SEC;
    printf("\nExecution Time: %.7f seconds\n", executionTime);
    return 0;
}