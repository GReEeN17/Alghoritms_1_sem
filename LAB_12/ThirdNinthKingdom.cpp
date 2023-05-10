#include <iostream>
#include <vector>
using namespace std;

struct Road {
    int source;
    int destination;
    int weight;
    bool isInMst;
};

class ThirdNinthKingdom {
private:
    int countVertexes;
    int countEdges;
    vector<int> parent;
    vector<int> rank;
    vector<Road> roads;
    vector<bool> mst;
    vector<int> indexes;

    vector<vector<pair<int, int>>> graphMST;
    vector<int> parentLCA;
    vector<int> usedLCA;
    vector<int> heightLCA;

    int partition( int left, int right) {
        int elem = roads[(left + right) / 2].weight;
        int i = left, j = right;
        while (i <= j) {
            while (roads[i].weight < elem) {
                i++;
            }
            while (roads[j].weight > elem) {
                j--;
            }
            if (i >= j) {
                break;
            }
            std::swap(indexes[i], indexes[j]);
            std::swap(roads[i++], roads[j--]);
        }
        return j;
    }

    void quicksort(int left, int right) {
        if (left < right) {
            int q = partition(left, right);
            quicksort(left, q);
            quicksort(q + 1, right);
        }
    }

public:
    vector<int> indexesMin;

    ThirdNinthKingdom(int N, int M) {
        countVertexes = N;
        countEdges = M;
        mst.assign(countEdges, false);
        for (int i = 0; i < countEdges; i++) {
            indexes.push_back(i);
        }
        for (int i = 0; i < countVertexes; i++) {
            parent.push_back(i);
            rank.push_back(1);
            parentLCA.push_back(INT_MAX);
            heightLCA.push_back(INT_MAX);
            usedLCA.push_back(false);
        }
    }

    void addRoad(int source, int destination, int weight, bool isInMST) {
        roads.push_back(Road{source, destination, weight, isInMST});
    }

    void sortRoads() {
        quicksort(0, countEdges - 1);
    }

    int getSource(int index) {
        return roads[index].source;
    }

    int getDestination(int index) {
        return roads[index].destination;
    }

    int getWeight(int index) {
        return roads[index].weight;
    }

    bool ifInMST(int index) {
        return roads[index].isInMst;
    }

    int getIndex(int index) {
        return indexes[index];
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

    int kruscal(int time) {
        for (int i = 0; i < countEdges; i++) {
            int topFirst = findSet(roads[i].source);
            int topSecond = findSet(roads[i].destination);
            if (topFirst != topSecond) {
                time += roads[i].weight;
                mst[i] = true;
                roads[i].isInMst = true;
                unionSets(topFirst, topSecond);
            }
        }
        return time;
    }

    void makeMST() {
        graphMST.resize(countVertexes, vector<pair<int, int>>());
        for (Road road : roads) {
            if (road.isInMst) {
                graphMST[road.source].push_back({road.destination, road.weight});
                graphMST[road.destination].push_back({road.source, road.weight});
            }
        }
    }

    void dfsLCA(int current, int previous, int heightCurrent) {
        heightLCA[current] = heightCurrent;
        parentLCA[current] = previous;
        usedLCA[current] = true;
        for (int i = 0; i < graphMST[current].size(); i++) {
            int dest = graphMST[current][i].first;
            if (!usedLCA[dest]) {
                if (dest != previous) {
                    dfsLCA(dest, current, heightCurrent + 1);
                }
            }
        }
    }

    int compareWeight(int source, int destination, int res) {
        for (pair<int, int> p : graphMST[source]) {
            if (p.first == destination) {
                if (p.second > res) {
                    res = p.second;
                }
                break;
            }
        }
        return res;
    }

    int LCA(int source, int destination) {
        int heightSource = heightLCA[source];
        int heightDestination = heightLCA[destination];
        int res = 0;
        while (heightSource != heightDestination) {
            if (heightSource < heightDestination) {
                res = compareWeight(destination, parentLCA[destination], res);
                destination = parentLCA[destination];
                heightDestination--;
            } else {
                res = compareWeight(source, parentLCA[source], res);
                source = parentLCA[source];
                heightSource--;
            }
        }
        while (source != destination) {
            res = compareWeight(source, parentLCA[source], res);
            res = compareWeight(destination, parentLCA[destination], res);
            source = parentLCA[source];
            destination = parentLCA[destination];
            heightSource--;
            heightDestination--;
        }
        return res;
    }
};

int thirdNinthKingdom() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<Road> roads;
    ThirdNinthKingdom kingdom(N, M);
    for (int i = 0; i < M; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        roads.push_back(Road{source - 1, destination - 1, weight});
        kingdom.addRoad(source - 1, destination - 1, weight, false);
    }
    kingdom.sortRoads();
    int minMst = kingdom.kruscal(0);
    kingdom.makeMST();
    kingdom.dfsLCA(0, INT_MAX, 1);
    int res[M];
    for (int i = 0; i < M; i++) {
        if (kingdom.ifInMST(i)) {
            res[kingdom.getIndex(i)] = minMst;
        } else {
            int road = kingdom.LCA(kingdom.getSource(i), kingdom.getDestination(i));
            res[kingdom.getIndex(i)] = minMst - road + kingdom.getWeight(i);
        }
    }
    for (int i = 0; i < M; i++) {
        cout << res[i] << "\n";
    }
    return 0;
}




