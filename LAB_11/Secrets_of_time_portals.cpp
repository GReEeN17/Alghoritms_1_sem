#include <iostream>
using namespace std;

int secrets_of_time_portal() {
    int n, m, k;
    cin >> n >> m >> k;
    int** graph = new int*[n];
    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INT_MAX;
        }
    }
    int start, end, path;
    for (int i = 0; i < m; i++) {
        cin >> start >> end >> path;
        graph[start - 1][end - 1] = path;
    }
    for (int l = 0; l < n; l++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][l] == INT_MAX || graph[l][j] == INT_MAX) continue;
                if (abs(i - l) > k || abs(j - l) > k) continue;
                graph[i][j] = min(graph[i][j], graph[i][l] + graph[l][j]);
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> start >> end;
        if (graph[start - 1][end - 1] == INT_MAX) cout << -1 << "\n";
        else cout << graph[start - 1][end - 1] << "\n";
    }
    return 0;
}