#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class GraphTinder {
private:
    int countVertexes;
    int countEdges;
    vector<vector<int>> edges;
    vector<int> rank;
    vector<int> parent;
public:
    GraphTinder(int countVertexes, int countEdges);

    int findSet(int vertex);

    void addEdge(int vertexFirst, int vertexSecond);

    void unionSets(int vertexFirst, int vertexSecond);

    void deleteEdge(int start, int end);

    void makeSNM();
};

GraphTinder::GraphTinder(int countVertexes, int countEdges) {
    this->countVertexes = countVertexes;
    this->countEdges = countEdges;
    for (int i = 0; i < countVertexes; i++) {
        edges.emplace_back();
        parent.push_back(i);
        rank.push_back(1);
    }
}

void GraphTinder::addEdge(int vertexFirst, int vertexSecond) {
    edges[vertexFirst].push_back(vertexSecond);
    edges[vertexSecond].push_back(vertexFirst);
}

int GraphTinder::findSet(int vertex) {
    if (vertex == parent[vertex]) return vertex;
    return parent[vertex] = findSet(parent[vertex]);
}

void GraphTinder::unionSets(int vertexFirst, int vertexSecond) {
    vertexFirst = findSet(vertexFirst);
    vertexSecond = findSet(vertexSecond);
    if (vertexFirst != vertexSecond) {
        if (rank[vertexFirst] < rank[vertexSecond]) {
            parent[vertexFirst] = vertexSecond;
        } else if(rank[vertexSecond] < rank[vertexFirst]) {
            parent[vertexSecond] = vertexFirst;
        } else {
            parent[vertexFirst] = vertexSecond;
            rank[vertexSecond]++;
        }
    }
}

void GraphTinder::deleteEdge(int start, int end) {
    int i = 0;
    while (edges[start][i] != end) i++;
    edges[start].erase(edges[start].begin() + i);
}

void GraphTinder::makeSNM() {
    for (int i = 0; i < countVertexes; i++) {
        for (int j = 0; j < edges[i].size(); j++) {
            unionSets(i, edges[i][j]);
        }
    }
}

int tinderSecond() {
    int n, m, q;
    cin >> n >> m >> q;
    GraphTinder graph = GraphTinder(n, m);
    for (int i = 0; i < m; i++) {
        int vertexFirst, vertexSecond;
        cin >> vertexFirst >> vertexSecond;
        graph.addEdge(vertexFirst - 1, vertexSecond - 1);
    }
    stack<vector<int>> requests;
    for (int i = 0; i < q; i++) {
        char sign;
        int vertexFirst, vertexSecond, requestSign = 0;
        cin >> sign >> vertexFirst >> vertexSecond;
        if (sign == '-') {
            requestSign = 1;
            graph.deleteEdge(vertexFirst - 1, vertexSecond - 1);
            graph.deleteEdge(vertexSecond - 1, vertexFirst - 1);
        }
        requests.push({requestSign, vertexFirst - 1, vertexSecond - 1});
    }
    graph.makeSNM();
    stack<string> res;
    while (!requests.empty()) {
        vector<int> request = requests.top();
        requests.pop();
        if (request[0] == 0) res.emplace(graph.findSet(request[1]) == graph.findSet(request[2]) ? "YES" : "NO");
        else graph.unionSets(request[1], request[2]);
    }
    while (!res.empty()) {
        cout << res.top() << "\n";
        res.pop();
    }
    return 0;
}