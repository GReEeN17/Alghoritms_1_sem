#include <iostream>
#include <vector>
using namespace std;

void dfs_ct(vector<vector<int>> &adj, vector<bool> &visited, int v) {
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u]) {
            dfs_ct(adj, visited, u);
        }
    }
}

int np_complete_task() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> count(n, 0);
    vector<bool> visited(n, false);
    int count_1 = 0, count_2 = 0;
    int temp_1, temp_2;
    for (int i = 0; i < m; i++) {
        cin >> temp_1 >> temp_2;
        temp_1--; temp_2--;
        if (count[temp_1] == 0) {
            count_1++;
        } else if (count[temp_1] == 1) {
            count_1--;
            count_2++;
        } else {
            count_2--;
        }
        if (count[temp_2] == 0) {
            count_1++;
        } else if (count[temp_2] == 1) {
            count_1--;
            count_2++;
        } else {
            count_2--;
        }
        count[temp_1]++;
        count[temp_2]++;
        adj[temp_1].push_back(temp_2);
        adj[temp_2].push_back(temp_1);
    }
    dfs_ct(adj, visited, 0);
    bool flag = true;
    for (auto fl : visited) {
        if (!fl) {
            flag = false;
        }
    }
    if (count_1 + count_2 == n && count_1 == 2 && flag) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
    return 0;
}