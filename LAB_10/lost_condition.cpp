#include <iostream>
#include <vector>
using namespace std;

void dfs_lost_condition(int v, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &res) {
    visited[v] = true;
    for (int i : graph[v]) {
        if (!visited[i]) {
            dfs_lost_condition(i, graph, visited, res);
        }
    }
    res.push_back(v);
}

void top_sort(int n, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &res) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs_lost_condition(i, graph, visited, res);
        }
    }
    reverse(res.begin(), res.end());
}

int lost_condition() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        graph.emplace_back();
    }
    int vert_1, vert_2;
    for (int i = 0; i < m; i++) {
        cin >> vert_1 >> vert_2;
        vert_1--; vert_2--;
        graph[vert_1].push_back(vert_2);
    }
    vector<bool> visited(n, false);
    vector<int> res(n);
    top_sort(n, graph, visited, res);
    int answer[n];
    for (int i = 0; i < n; i++) {
        answer[res[i]] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    return 0;
}