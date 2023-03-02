#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    vector<int> *arr_paths;
    bool *visited;
    int vertexes;
public:

    Graph(int v);

    void add_edge(int dep, int dest);

    void dfs(int vertex);

    void reset_visited();
};

Graph::Graph(int v) {
    vertexes = v;
    arr_paths = new vector<int>[vertexes];
    visited = new bool[vertexes];
}

void Graph::add_edge(int dep, int dest) {
    arr_paths[dep].push_back(dest);
}

void Graph::dfs(int vertex) {
    visited[vertex] = true;
    vector<int> arr_path = arr_paths[vertex];
    cout << vertex << "\n";
    vector<int>::iterator i;
    for (i = arr_path.begin(); i != arr_path.end(); i++) {
        cout << visited[*i] << " " << *i << "\n";
        if (!visited[*i]) dfs(*i);
    }
}

void Graph::reset_visited() {
    for (int i = 0; i < vertexes; i++) {
        visited[i] = false;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    int temp_1, temp_2;
    for (int i = 0; i < m; i++) {
        cin >> temp_1 >> temp_2;
        g.add_edge(temp_1, temp_2);
        g.add_edge(temp_2, temp_1);
    }
    for (int i = 1; i <= n; i++) {
        g.dfs(i);
        g.reset_visited();
        cout << "------------------" << "\n";
    }
}
//When i graduated from school I was totally disillusioned, that i won't see my classmates every day. I was frusatrated
//with this fact, but I understood that on that my life doesn't stop. And i was totally right. When I enrolled in university I
// felt gleeful that I met so amny new friends. Also I was petrified when