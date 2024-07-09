#include <stdio.h>
#include <limits.h>

#define VERTICES_MAX 20

int shortestPath(int g[VERTICES_MAX][VERTICES_MAX], int v, int s, int d) {
    int d_v[VERTICES_MAX];
    int vstd[VERTICES_MAX];
    int p[VERTICES_MAX];
	int i;

    for (i = 0; i < v; i++) {
        d_v[i] = INT_MAX;
        vstd[i] = 0;
        p[i] = -1;
    }

    d_v[s] = 0;
	int c;

    for (c = 0; c < v - 1; c++) {
        int u = -1;
        int mv = INT_MAX;
        int j;

        for (j = 0; j < v; j++) {
            if (!vstd[j] && d_v[j] <= mv) {
                mv = d_v[j];
                u = j;
            }
        }

        vstd[u] = 1;
        int w;

        for (w = 0; w < v; w++) {
            if (!vstd[w] && g[u][w] && d_v[u] != INT_MAX && d_v[u] + g[u][w] < d_v[w]) {
                d_v[w] = d_v[u] + g[u][w];
                p[w] = u;
            }
        }
    }

    printf("Distance from %d to %d: %d\n", s, d, d_v[d]);
    printf("Path: %d", s);

    int j = d;

    while (p[j] != -1) {
        printf(" -> %d", j);
        j = p[j];
    }

    printf("\n");
}

int main() {
    int v, s, d;

    printf("Enter vertices: ");
    scanf("%d", &v);

    int g[VERTICES_MAX][VERTICES_MAX];

    printf("Enter adjacency matrix:\n");

    int i, j;
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            scanf("%d", &g[i][j]);
        }
    }

    printf("Enter source: ");
    scanf("%d", &s);

    printf("Enter destination: ");
    scanf("%d", &d);

    shortestPath(g, v, s, d);

    return 0;
}
