#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class OptimizationGenius {
private:
    struct Edge {
        int source;
        int destination;
        int weight;
    };

    int countVertexes, countEdges;
    vector<vector<int>> graph;
    vector<Edge> edges;
    vector<int> parents;
    vector<bool> used;

    bool bfsOptimizationGenius (int begin, int end) {
        used.assign(countVertexes, true);
        queue<int> q;
        q.push(begin);
        used[begin] = true;
        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            for (int i = 0; i < countVertexes; i++) {
                if (graph[vertex][i] > 0 && used[i]) {
                    parents[i] = vertex;
                    used[i] = false;
                    q.push(i);
                }
            }
        }
        return used[end];
    }
public:
    OptimizationGenius(int N, int M) {
        this->countVertexes= N;
        this->countEdges = M;
        graph.resize(M, vector<int>(M));
        parents.resize(M);
        used.resize(M);
    }

    void addEdge(int source, int destination, int weight) {
        edges.push_back(Edge{source, destination, weight});
        graph[source][destination] = weight;
    }

    void fordFalkerson(int start, int end) {
        int maxFlow = 0;
        while (!bfsOptimizationGenius(start, end)) {
            int tempFlow = INT_MAX;
            for (int i = end; i != start; i = parents[i]) {
                int temp = parents[i];
                tempFlow = min(tempFlow, graph[temp][i]);
            }
            for (int i = end; i != start; i = parents[i]) {
                int temp = parents[i];
                graph[temp][i] -= tempFlow;
                graph[i][temp] += tempFlow;
            }
            maxFlow += tempFlow;
         }
        cout << maxFlow;
    }
};

int optimizationKing() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    OptimizationGenius flow(N, M);
    for (int i = 0; i < M; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        flow.addEdge(source - 1, destination - 1, weight);
    }
    flow.fordFalkerson(0, N - 1);
    return 0;
}
