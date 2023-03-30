#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs_tinder(int start, int end, vector<vector<int>> &graph, vector<bool> &visited) {
    visited[start] = true;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (!visited[v]) {
                q.push(v);
            }
            if (v == end) {
                cout << "YES" << "\n";
                return;
            }
        }
        visited[u] = true;
    }
    cout << "NO" << "\n";
}

void delete_edge(int start, int end, vector<vector<int>> &graph) {
    int i = 0;
    while (graph[start][i] != end) i++;
    graph[start].erase(graph[start].begin() + i);
}

int tinder() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        graph.emplace_back();
    }
    for (int i = 0; i < n; i++) {
        graph[i].push_back(i);
    }
    int vert_1, vert_2;
    for (int i = 0; i < m; i++) {
        cin >> vert_1 >> vert_2;
        vert_1--; vert_2--;
        graph[vert_1].push_back(vert_2);
        graph[vert_2].push_back(vert_1);
    }
    vector<bool> visited(n, false);
    char request;
    for (int i = 0; i < q; i++) {
        cin >> request >> vert_1 >> vert_2;
        vert_1--; vert_2--;
        if (request == '?') {
            if (vert_1 > n - 1 || vert_2 > n - 1) {
                cout << "NO" << "\n";
                continue;
            }
            for (int j = 0; j < n; j++) {
                visited[j] = false;
            }
            bfs_tinder(vert_1, vert_2, graph, visited);
        } else if (request == '-') {
            delete_edge(vert_1, vert_2, graph);
            delete_edge(vert_2, vert_1, graph);
        }
    }
    return 0;
}