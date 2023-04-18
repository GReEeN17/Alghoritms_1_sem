#include <iostream>
using namespace std;

class GraphVyazma {
private:
    struct Edge {
        int source;
        int destination;
        int weight;
    };
    int vertexes;
    int countEdges;
    vector<Edge> edges;
    int *dist;

    void checkDist(int q);
public:
    GraphVyazma(int vertexes, int countEdges);

    void addEdge(int source, int destination, int weight);

    void fordBellman(int start, int q);
};

GraphVyazma::GraphVyazma(int vertexes, int countEdges) {
    this->vertexes = vertexes;
    this->countEdges = countEdges;
    dist = new int[vertexes];
}

void GraphVyazma::addEdge(int source, int destination, int weight) {
    Edge edge = Edge();
    edge.source = source;
    edge.destination = destination;
    edge.weight = weight;
    edges.push_back(edge);
}

void GraphVyazma::fordBellman(int start, int q) {
    for (int i = 0; i < vertexes; i++) {
        dist[i] = INT_MAX;
    }
    dist[start] = 0;
    for (int i = 0; i < vertexes - 1; i++) {
        bool changed = false;
        for (Edge edge : edges) {
            if (dist[edge.source] == INT_MAX) continue;
            if (dist[edge.destination] > dist[edge.source] + edge.weight) {
                dist[edge.destination] = dist[edge.source] + edge.weight;
                changed = true;
            }
        }
        if (!changed) break;
    }
    checkDist(q);
}

void GraphVyazma::checkDist(int q) {
    for (int i = 0; i < q; i++) {
        int dest;
        cin >> dest;
        cout << (dist[dest - 1] == INT_MAX ? -1 : dist[dest - 1]) << "\n";
    }
}

int main() {
    int n, m, q, start;
    cin >> n >> m >> q >> start;
    GraphVyazma graph = GraphVyazma(n, m);
    for (int i = 0; i < m; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph.addEdge(source - 1, destination - 1, weight);
        graph.addEdge(destination - 1, source - 1, weight);
    }
    graph.fordBellman(start - 1, q);
}
