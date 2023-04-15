#include <iostream>
using namespace std;

int mito_hype_park() {
    int n, m;
    cin >> n >> m;
    int** graph = new int*[n];
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INT_MAX;
            }
        }
    }
    for(int i = 0; i < m; i++) {
        int start, finish, weight;
        cin >> start >> finish >> weight;
        graph[start - 1][finish - 1] = weight;
        graph[finish - 1][start - 1] = weight;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][k] == INT_MAX || graph[k][j] == INT_MAX) continue;
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    int maxx = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] > maxx && graph[i][j] < INT_MAX) {
                maxx = graph[i][j];
            }
        }
    }
    cout << maxx;
    return 0;
}