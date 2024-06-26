#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void DFSUtil(int v, bool visited[], int adjMatrix[MAX][MAX], int V) {
    visited[v] = true;
    printf("%d ", v);

    for (int i = 0; i < V; i++) {
        if (adjMatrix[v][i] == 1 && !visited[i])
            DFSUtil(i, visited, adjMatrix, V);
    }
}

void DFS(int adjMatrix[MAX][MAX], int V) {
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            DFSUtil(i, visited, adjMatrix, V);
    }
}

int main() {
    int V = 4;
    int adjMatrix[MAX][MAX] = {{0, 1, 1, 0},
                               {1, 0, 0, 1},
                               {1, 0, 0, 1},
                               {0, 1, 1, 0}};
    
    printf("Depth First Traversal:\n");
    DFS(adjMatrix, V);

    return 0;
}

