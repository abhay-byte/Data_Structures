#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct N {
    int data;
    struct N* next;
} N;

typedef struct Gh {
    int V;
    N** adjL;
} Gh;

N* createN(int data) {
    N* newN = (N*)malloc(sizeof(N));
    newN->data = data;
    newN->next = NULL;
    return newN;
}

Gh* createGh(int V) {
    Gh* gh = (Gh*)malloc(sizeof(Gh));
    gh->V = V;
    gh->adjL = (N**)malloc(V * sizeof(N*));
    for (int i = 0; i < V; i++) gh->adjL[i] = NULL;
    return gh;
}

void AddEdge(Gh* gh, int src, int dest) {
    N* newN = createN(dest);
    newN->next = gh->adjL[src];
    gh->adjL[src] = newN;
    printf("Edge added: %d -> %d\n", src, dest);
    newN = createN(src);
    newN->next = gh->adjL[dest];
    gh->adjL[dest] = newN;
}

void BFS(Gh* gh, int start) {
    bool* done = (bool*)malloc(gh->V * sizeof(bool));
    for (int i = 0; i < gh->V; i++) done[i] = false;
    int* Q = (int*)malloc(gh->V * sizeof(int));
    int front = 0, rear = 0;
    done[start] = true;
    Q[rear++] = start;
    printf("BFS from %d: ", start);
    while (front < rear) {
        int current = Q[front++];
        printf("%d ", current);
        N* T = gh->adjL[current];
        while (T != NULL) {
            int adjVx = T->data;
            if (!done[adjVx]) {
                done[adjVx] = true;
                Q[rear++] = adjVx;
            }
            T = T->next;
        }
    }
    printf("\n");
    free(done);
    free(Q);
}

void Util(Gh* gh, int vx, bool* done) {
    done[vx] = true;
    printf("%d ", vx);
    N* T = gh->adjL[vx];
    while (T != NULL) {
        int adjVx = T->data;
        if (!done[adjVx])
            Util(gh, adjVx, done);
        T = T->next;
    }
}

void DFS(Gh* gh, int start) {
    bool* done = (bool*)malloc(gh->V * sizeof(bool));
    for (int i = 0; i < gh->V; i++) done[i] = false;
    printf("DFS from %d: ", start);
    Util(gh, start, done);
    printf("\n");
    free(done);
}

void main() {
    Gh* gh = createGh(4);
    AddEdge(gh, 0, 1);
    AddEdge(gh, 0, 2);
    AddEdge(gh, 1, 2);
    BFS(gh, 2);
    DFS(gh, 2);
    for (int i = 0; i < gh->V; i++) {
        N* T = gh->adjL[i];
        while (T != NULL) {
            N* next = T->next;
            free(T);T = next;
        }
    }free(gh->adjL);free(gh);
    printf("Abhay Raj, 00976803122\n");
}
