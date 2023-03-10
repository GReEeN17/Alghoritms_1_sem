#include <iostream>
#include <vector>
using namespace std;

class CT_graph {
private:
    vector<vector<int>>matrix;
    int vertexes;
    vector<int> path;
    vector<int> c;
public:
    CT_graph(int v);

    void add_edge(int dep, int dest);

    bool gamilton(int v, int v0);
};

CT_graph::CT_graph(int v) {
    vertexes = v;
    matrix = vector<vector<int>>(v);
    for (int i = 0; i < v; i++) {
        matrix[i] = vector<int>(v, 0);
    }
    path = vector<int>(v, 0);
    c = vector<int>(v, -1);
}

void CT_graph::add_edge(int dep, int dest) {
    matrix[dep][dest] = 1;
    matrix[dest][dep] = 1;
}

bool CT_graph::gamilton(int v, int v0) {
    bool q = false;
    for (int i = 0; i < vertexes && !q; i++) {
        if (matrix[i][path[v - 1]] | matrix[path[v - 1]][i]) {
            if (v == vertexes && i == v0) q = true;
            else if (c[i] == -1) {
                c[i] = v;
                path[v] = i;
                q = gamilton(v + 1, v0);
                if (!q) c[v] = -1;
            } else continue;
        }
    }
    return q;
}

int main() {
    int n, m;
    cin >> n >> m;
    CT_graph g(n);
    int temp_1, temp_2;
    for (int i = 0; i < m; i++) {
        cin >> temp_1 >> temp_2;
        g.add_edge(temp_1 - 1, temp_2 - 1);
    }
    if (g.gamilton(1, 1)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}