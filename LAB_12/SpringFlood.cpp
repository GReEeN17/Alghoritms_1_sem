#include <iostream>
#include <vector>
using namespace std;

class SpringFlood {
private:
    struct Bridge {
        int source;
        int destination;
        int weight;
    };
    vector<int> parent;
    vector<int> rank;
    vector<Bridge> bridges;
public:
    SpringFlood(int N) {
        for (int i = 0; i < N; i++) {
            parent.push_back(i);
            rank.push_back(1);
        }
    }

    void addBridge(int source, int destination, int weight) {
        bridges.push_back(Bridge{source, destination, weight});
    }

    void sortBridges() {
        sort(bridges.begin(), bridges.end(),
             [](Bridge &first, Bridge &second){return first.weight < second.weight;});
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

    int kruscal(int bridgeCount) {
        int days = 0;
        for (int i = 0; i < bridgeCount; i++) {
            int topFirst = findSet(bridges[i].source);
            int topSecond = findSet(bridges[i].destination);
            if (topFirst != topSecond) {
                days += bridges[i].weight;
                unionSets(topFirst, topSecond);
            }
        }
        return days;
    }
};

int springFlood1() {
    int N, M;
    cin >> N >> M;
    SpringFlood springFlood(N);
    for (int i = 0; i < M; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        springFlood.addBridge(source - 1, destination - 1, weight);
    }
    springFlood.sortBridges();
    cout << springFlood.kruscal(M);
    return 0;
}