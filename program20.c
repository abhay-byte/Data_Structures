#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#define V 6
typedef struct {
    int vx;
    int** adjMat;
} Gh;

Gh* CreateGh(int vx) {
    Gh* G = malloc(sizeof(Gh));
    G->vx = vx;
    G->adjMat = malloc(vx * sizeof(int*));
    for (int i = 0; i < vx; i++) G->adjMat[i] = calloc(vx, sizeof(int));
    return G;
}

void AddEdge(Gh* G, int s, int d, int w) {
    G->adjMat[s][d] = w;
    G->adjMat[d][s] = w;
}

void ShortestPath(Gh* G, int src) {
    int dist[V]; bool sptSet[V];
    for (int i = 0; i < V; i++) dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, u;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && dist[v] <= min)
                min = dist[v], u = v;
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && G->adjMat[u][v] && dist[u] != INT_MAX &&
                dist[u] + G->adjMat[u][v] < dist[v])
                dist[v] = dist[u] + G->adjMat[u][v];
    }
    printf("Vertex \t Dist from Source\n");
    for (int i = 0; i < V; i++) printf("%d \t %d\n", i, dist[i]);
}

void main() {
    Gh* G = CreateGh(V);
    AddEdge(G, 0, 1, 4);
    AddEdge(G, 0, 2, 1);
    AddEdge(G, 1, 2, 2);
    AddEdge(G, 1, 3, 5);
    AddEdge(G, 2, 3, 1);
    AddEdge(G, 3, 4, 3);
    AddEdge(G, 4, 5, 2);
    ShortestPath(G, 0);
    for (int i = 0; i < V; i++) free(G->adjMat[i]);
    free(G->adjMat);free(G);
    printf("Abhay Raj, 00976803122\n");
}
