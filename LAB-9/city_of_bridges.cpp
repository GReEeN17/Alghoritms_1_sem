#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    vector<vector<int>>arr_paths;
    vector<int> visited;
    int vertexes;
public:
    bool cycle_found = false;

    Graph(int v);

    void add_edge(int dep, int dest);

    void dfs(int vertex, int start, int len);

    void reset_visited();
};

Graph::Graph(int v) {
    vertexes = v;
    arr_paths = vector<vector<int>>(vertexes);
    visited = vector<int>(vertexes);
}

void Graph::add_edge(int dep, int dest) {
    arr_paths[dep].push_back(dest);
}

void Graph::dfs(int vertex, int prev, int start) {
    visited[vertex] = 1;
    vector<int> arr_path = arr_paths[vertex];
    vector<int>::iterator i;
    for (i = arr_path.begin(); i != arr_path.end(); i++) {
        if (visited[*i] == 0) {
            dfs(*i, vertex, start);
        } else if (visited[*i] == 1 && *i != prev) {
            cycle_found = true;
            break;
        }
    }
    visited[vertex] = 2;
}

void Graph::reset_visited() {
    visited = {0};
}

int city_of_bridges() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    int temp_1, temp_2;
    for (int i = 0; i < m; i++) {
        cin >> temp_1 >> temp_2;
        g.add_edge(temp_1 - 1, temp_2 - 1);
        g.add_edge(temp_2 - 1, temp_1 - 1);
    }
    for (int i = 0; i < n; i++) {
        g.dfs(i, -1, i);
        if (g.cycle_found) {
            cout << "YES" << "\n";
            return 0;
        }
        g.reset_visited();
    }
    cout << "NO" << "\n";
    return 0;
}