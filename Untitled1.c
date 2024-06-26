#include <stdio.h>
#include <limits.h>

#define V 4

int tsp(int graph[][V], int s) {
    int dp[1 << V][V];
    for (int i = 0; i < (1 << V); i++)
        for (int j = 0; j < V; j++)
            dp[i][j] = INT_MAX;

    dp[1 << s][s] = 0;

    for (int mask = 0; mask < (1 << V); mask++) {
        for (int u = 0; u < V; u++) {
            if (mask & (1 << u)) {
                for (int v = 0; v < V; v++) {
                    if (!(mask & (1 << v)) && graph[u][v]) {
                        int nextMask = mask | (1 << v);
                        dp[nextMask][v] = (dp[nextMask][v] < dp[mask][u] + graph[u][v]) ? dp[nextMask][v] : dp[mask][u] + graph[u][v];
                    }
                }
            }
        }
    }

    int res = INT_MAX;
    for (int i = 0; i < V; i++) {
        if (i != s && graph[i][s]) {
            res = (res < dp[(1 << V) - 1][i] + graph[i][s]) ? res : dp[(1 << V) - 1][i] + graph[i][s];
        }
    }

    return res;
}

int main() {
    int graph[][V] = {{0, 10, 15, 20},
                      {10, 0, 35, 25},
                      {15, 35, 0, 30},
                      {20, 25, 30, 0}};
    int s = 0;
    printf("The minimum cost of travelling salesman problem is %d", tsp(graph, s));
    return 0;
}

