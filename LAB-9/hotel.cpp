#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class GraphHotel {
private:
    vector<vector<int>> adj_list;
    int vertexes;
public:
    GraphHotel(int v);

    void add_edge(int dep, int dest);

    int bfs(int s, int f);
};

GraphHotel::GraphHotel(int v) {
    vertexes = v;
    adj_list = vector<vector<int>>(vertexes);
}

void GraphHotel::add_edge(int dep, int dest) {
    adj_list[dep].push_back(dest);
}

int GraphHotel::bfs(int s, int f) {
    vector<int> dist(vertexes, vertexes);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj_list[v]) {
            if (dist[u] > dist[v] + 1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    return dist[f] == vertexes ? -1 : dist[f];
}

int hotel_graph() {
    int n, m;
    cin >> n >> m;
    GraphHotel g(n);
    int temp_1, temp_2;
    for (int i = 0; i < m; i++) {
        cin >> temp_1 >> temp_2;
        g.add_edge(temp_1 - 1, temp_2 - 1);
        g.add_edge(temp_2 - 1, temp_1 - 1);
    }
    int s, f;
    cin >> s >> f;
    cout << g.bfs(s - 1, f - 1) << "\n";
    return 0;
}