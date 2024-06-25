#include <stdio.h>
#include <limits.h>

#define V 4
#define INF INT_MAX

int tsp(int graph[][V], int setOfCities, int pos, int dp[][1 << V]) {
    if (setOfCities == ((1 << V) - 1)) {
        return graph[pos][0];
    }
    
    if (dp[pos][setOfCities] != -1) {
        return dp[pos][setOfCities];
    }
    
    int min = INF;
    
    for (int city = 0; city < V; city++) {
        if ((setOfCities & (1 << city)) == 0) {
            int newCost = graph[pos][city] + tsp(graph, setOfCities | (1 << city), city, dp);
            if (newCost < min) {
                min = newCost;
            }
        }
    }
    
    return dp[pos][setOfCities] = min;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    
    int dp[V][1 << V];
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < (1 << V); j++) {
            dp[i][j] = -1;
        }
    }
    
    printf("The cost of the most efficient tour is %d\n", tsp(graph, 1, 0, dp));
    
    return 0;
}

