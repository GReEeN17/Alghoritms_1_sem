#include <iostream>
#include <vector>
using namespace std;

void dfs_hogwarts(int k, int v, vector<int>& comp, vector<bool>& visited, vector<vector<int>>& graph) {
    visited[v] = true;
    comp[v] = k;
    vector<int> arr_path = graph[v];
    vector<int>::iterator i;
    for (i = arr_path.begin(); i != arr_path.end(); i++) {
        if (!visited[*i]) {
            dfs_hogwarts(k, *i,comp, visited, graph);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    vector<vector<int>> graph(m);
    for (int i = 0; i < n; i++) {
        graph.emplace_back();
    }
    vector<int> traps(n);
    vector<int> comp(n, 0);
    vector<bool> visited(n, false);
    int res = 0;
    int temp_1, temp_2;
    for (int i = 0; i < m; i++) {
        cin >> temp_1 >> temp_2;
        temp_1--; temp_2--;
        graph[temp_1].push_back(temp_2);
        graph[temp_2].push_back(temp_1);
    }
    for (int i = 0; i < n; i++) {
        cin >> temp_1;
        traps[i] = temp_1;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            res++;
            dfs_hogwarts(res, i, comp, visited, graph);
        }
    }
    vector<int> traps_comp(res, 0);
    for (int i = 0; i < n; i++) {
        if (traps[i] == 1) {
            traps_comp[comp[i] - 1] = 1;
        }
    }
    cout << res << "\n";
    for (int i = 0; i < n; i++) {
        cout << comp[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < res; i++) {
        cout << traps_comp[i] << " ";
    }
    cout << "\n";
    return 0;
}