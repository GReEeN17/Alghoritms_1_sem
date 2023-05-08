#include <iostream>
using namespace std;

class GraphFacecontrol {
private:
    struct Edge {
        int source;
        int destination;
        int weight;
    };
    int vertexes;
    int edges;
    vector<Edge> edge;
    int* dist;
    int* previous;
    int maxNegativeCycle;

    void checkCycles();
public:
    GraphFacecontrol(int vertexes, int edges, int maxNegativeCycle);

    void addEdge(int source, int destination, int weight);

    void fordBellman();
};

GraphFacecontrol::GraphFacecontrol(int vertexes, int edges, int maxNegativeCycle) {
    this->vertexes = vertexes;
    this->edges = edges;
    this->maxNegativeCycle = maxNegativeCycle;
    dist = new int[vertexes];
    previous = new int[vertexes];
}

void GraphFacecontrol::addEdge(int source, int destination, int weight) {
    Edge gapEdge = Edge();
    gapEdge.source = source;
    gapEdge.destination = destination;
    gapEdge.weight = weight;
    edge.push_back(gapEdge);
}

void GraphFacecontrol::fordBellman() {
    for (int i = 0; i < vertexes; i++) {
        dist[i] = INT_MAX;
        previous[i] = INT_MIN;
    }
    dist[edge[0].source] = 0;
    for (int i = 0; i < vertexes - 1; i++) {
        bool changed = false;
        for (Edge edg : edge) {
            if (dist[edg.source] == INT_MAX) continue;
            if (dist[edg.destination] > dist[edg.source] + edg.weight) {
                dist[edg.destination] = dist[edg.source] + edg.weight;
                previous[edg.destination] = edg.source;
                changed = true;
            }
        }
        if (!changed) break;
    }
    checkCycles();
}

void GraphFacecontrol::checkCycles() {
    int lenNegativeCycle = 0;
    for (Edge edg : edge) {
        if (dist[edg.source] == INT_MAX) continue;
        if (dist[edg.destination] > dist[edg.source] + edg.weight) {
            for (int i = 0; i < vertexes - 1; i++) {
                edg.destination = previous[edg.destination];
            }
            edg.source = edg.destination;
            while (edg.source != previous[edg.destination]) {
                lenNegativeCycle++;
                edg.destination = previous[edg.destination];
            }
        }
    }
    cout << ((lenNegativeCycle < maxNegativeCycle || lenNegativeCycle == 0) ? "YES" : "NO") << "\n";
}

int facecontrol() {
    int N, k;
    cin >> N >> k;
    for (int i = 0; i < N; i++) {
        int n, m;
        cin >> n >> m;
        GraphFacecontrol graph = GraphFacecontrol(n, m, k);
        for (int j = 0; j < m; j++) {
            int source, destination, weight;
            cin >> source >> destination >> weight;
            graph.addEdge(source - 1, destination - 1, weight);
        }
        graph.fordBellman();
    }
    return 0;
}