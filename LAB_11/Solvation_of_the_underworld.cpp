#include <iostream>
#include <stack>
using namespace std;

void top_sort_dag(int** graph, bool *visited, int v, int n, stack<int> &top_sort) {
    visited[v] = true;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] != INT_MAX && !visited[i]) {
            top_sort_dag(graph, visited, i, n, top_sort);
        }
    }
    top_sort.push(v);
}

int solvation_of_the_underworld() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    int** graph = new int*[n];
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < m; i++) {
        int start, finish, weight;
        cin >> start >> finish >> weight;
        graph[start - 1][finish - 1] = weight;
    }
    stack<int> top_sort;
    bool visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    top_sort_dag(graph, visited, s - 1, n, top_sort);
    int dist[n];
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[s - 1] = 0;
    while (!top_sort.empty()) {
        int u = top_sort.top();
        top_sort.pop();
        if (dist[u] != INT_MAX) {
            for (int i = 0; i < n; i++) {
                if (graph[u][i] != INT_MAX) {
                    if (dist[i] > dist[u] + graph[u][i]) {
                        dist[i] = dist[u] + graph[u][i];
                    }
                }
            }
        }
    }
    cout << (dist[t - 1] == INT_MAX ? -1 : dist[t - 1]) << "\n";
    return 0;
}