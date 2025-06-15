//Write a program in C for Kruskal’s Algorithm Algorithm and also display its time and space complexity.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define V 5  // Number of vertices
#define E 7  // Number of edges
// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};
// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};
// Function to find set of an element i (uses path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to unite two subsets (by rank)
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
// Compare function for qsort
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}
// Function to construct MST using Kruskal's algorithm
void KruskalMST(struct Edge edges[]) {
    struct Edge result[V];  // To store the resultant MST
    int e = 0;              // Index for result[]
    int i = 0;              // Index for sorted edges

    // Sort all the edges in non-decreasing order of their weight
    qsort(edges, E, sizeof(edges[0]), compareEdges);
    // Create V subsets
    struct Subset subsets[V];
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1 && i < E) {
        struct Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge doesn't cause a cycle
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    // Print the result
    printf("Edge \tWeight\n");
    for (i = 0; i < e; ++i)
        printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
}
int main() {
    // Example graph
    struct Edge edges[E] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4},
        {1, 2, 25},
        {3, 4, 2}
    };
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    KruskalMST(edges);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n", cpu_time_used);
    return 0;
}
