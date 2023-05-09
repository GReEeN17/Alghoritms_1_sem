#include <iostream>
#include <vector>
using namespace std;

class CongressOfYoungScientists {
private:
    struct Fiber {
        int source;
        int destination;
        int weight;
    };
    vector<int> parent;
    vector<int> rank;
    vector<Fiber> fibers;
    vector<Fiber> mst;
public:
    explicit CongressOfYoungScientists(int N) {
        for (int i = 0; i < N; i++) {
            parent.push_back(i);
            rank.push_back(1);
        }
    }

    void clearRanksParents(int N) {
        for (int i = 0; i < N; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int getWeight(int index) {
        return fibers[index].weight;
    }

    int getSource(int index) {
        return fibers[index].source;
    }

    int getDestination(int index) {
        return fibers[index].destination;
    }

    void addBridge(int source, int destination, int weight) {
        fibers.push_back(Fiber{source, destination, weight});
    }

    void sortBridges() {
        sort(fibers.begin(), fibers.end(),
             [](Fiber &first, Fiber &second){return first.weight < second.weight;});
    }

    int findSet(int top) {
        if (top == parent[top]) {
            return top;
        }
        return parent[top] = findSet(parent[top]);
    }

    void unionSets(int topFirst, int topSecond) {
        topFirst = findSet(topFirst);
        topSecond = findSet(topSecond);
        if (topFirst != topSecond) {
            if (rank[topFirst] < rank[topSecond]) {
                parent[topFirst] = topSecond;
            } else if (rank[topFirst] > rank[topSecond]) {
                parent[topSecond] = topFirst;
            } else {
                rank[topSecond]++;
                parent[topFirst] = topSecond;
            }
        }
    }

    int kruscal(int fiberCount, int &index, int weight) {
        for (int i = 0; i < fiberCount; i++) {
            int topFirst = findSet(fibers[i].source);
            int topSecond = findSet(fibers[i].destination);
            if (topFirst != topSecond) {
                weight += fibers[i].weight;
                unionSets(topFirst, topSecond);
            } else {
                index = min(index, i);
            }
        }
        return weight;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    CongressOfYoungScientists congress(N);
    for (int i = 0; i < M; i++) {
        int  source, destination, weight;
        cin >> source >> destination >> weight;
        congress.addBridge(source - 1, destination - 1, weight);
    }
    congress.sortBridges();
    int index;
    int minWeight = congress.kruscal(M, index, 0);
    congress.clearRanksParents(N);
    congress.unionSets(congress.getSource(index), congress.getDestination(index));
    int minNextWeight = congress.kruscal(M, index, congress.getWeight(index));
    cout << minWeight << " " << minNextWeight;
    return 0;
}