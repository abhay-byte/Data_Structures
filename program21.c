#include <stdio.h>
#include <limits.h>
#define V 4
#define Max INT_MAX
void ShortestPath(int graph[][V]) {
    int dist[V][V];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != Max && dist[k][j] != Max &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printf("Matrix shows the shortest path between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == Max)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}
void main() {
    int graph[V][V] = {
        {0, 5, Max, 10},
        {Max, 0, 3, Max},
        {Max, Max, 0, 1},
        {Max, Max, Max, 0}
    };
    ShortestPath(graph);
    printf("Abhay Raj, 00976803122\n");
}
