#include <iostream>
#include <vector>
using namespace std;

class SpringFlood2 {
private:
    struct Bridge {
        long long source;
        long long destination;
        long long weight;
    };
    vector<long long> parent;
    vector<long long> rank;
    vector<Bridge> bridges;
public:
    SpringFlood2(long long N) {
        for (int i = 0; i < N; i++) {
            parent.push_back(i);
            rank.push_back(1);
        }
    }

    void addBridge(long long source, long long destination, long long weight) {
        bridges.push_back(Bridge{source, destination, weight});
    }

    void sortBridges() {
        sort(bridges.begin(), bridges.end(),
             [](Bridge &first, Bridge &second){return first.weight < second.weight;});
    }

    long long findSet(long long top) {
        if (top == parent[top]) {
            return top;
        }
        return parent[top] = findSet(parent[top]);
    }

    void unionSets(long long topFirst, long long topSecond) {
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

    long long kruscal(int bridgeCount) {
        long long days = 0;
        for (long long i = 0; i < bridgeCount; i++) {
            long long topFirst = findSet(bridges[i].source);
            long long topSecond = findSet(bridges[i].destination);
            if (topFirst != topSecond) {
                days += bridges[i].weight;
                unionSets(topFirst, topSecond);
            }
        }
        return days;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long N, M;
    cin >> N >> M;
    SpringFlood2 springFlood(N);
    for (long long i = 0; i < M; i++) {
        long long  source, destination, weight;
        cin >> source >> destination >> weight;
        springFlood.addBridge(source - 1, destination - 1, weight);
    }
    springFlood.sortBridges();
    cout << springFlood.kruscal(M);
    return 0;
}