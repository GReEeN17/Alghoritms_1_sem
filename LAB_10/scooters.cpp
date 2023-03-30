#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs_g(int v, vector<vector<int>> &g, vector<bool> &visited, stack<int> &s) {
    visited[v] = true;
    vector<int> adj_list = g[v];
    vector<int>::iterator i;
    for (i = adj_list.begin(); i != adj_list.end(); i++) {
        if (!visited[*i]) {
            dfs_g(*i, g, visited, s);
        }
    }
    s.push(v);
}

void dfs_h(int v, int components, vector<vector<int>> &h, vector<int> &comp) {
    comp[v] = components;
    vector<int> adj_list = h[v];
    vector<int>::iterator i;
    for (i = adj_list.begin(); i != adj_list.end(); i++) {
        if (comp[*i] == 0) {
            dfs_h(*i, components, h, comp);
        }
    }
}

int scooters() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n);
    vector<vector<int>> h(n);
    for (int i = 0; i < n; i++) {
        g.emplace_back();
        h.emplace_back();
    }
    int start, end;
    for (int i = 0; i < m; i++) {
        cin >> start >> end;
        start--;
        end--;
        g[start].push_back(end);
        h[end].push_back(start);
    }
    vector<bool> visited(n, false);
    vector<int> comp(n, 0);
    stack<int> s;
    int components;
    for (int i = 0; i < q; i++) {
        cin >> start >> end;
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                dfs_g(j, g, visited, s);
            }
        }
        components = 0;
        int v;
        while (!s.empty()) {
            v = s.top();
            s.pop();
            if (comp[v] == 0) {
                components++;
                dfs_h(v, components, h, comp);
            }
        }
        cout << (comp[start - 1] == comp[end - 1] ? "YES" : "NO") << "\n";
    }
    return 0;
}