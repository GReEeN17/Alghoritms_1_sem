/*
#include <iostream>
using namespace std;

int bellman_ford_vyazma(int** graph, int src, int n, int m) {
    int dist[n];
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != INT_MAX && dist[])
        }
    }
}

int in_search_of_vyazma() {
    int n, m, q, s;
    cin >> n >> m >> q >> s;
    int** graph = new int*[n];
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
    }
    for (int i = 0; i < m; i++) {
        int start, end, weight;
        cin >> start >> end >> weight;
        graph[start - 1][end - 1] = weight;
    }

}*/
