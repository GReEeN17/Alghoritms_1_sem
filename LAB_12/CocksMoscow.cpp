#include <iostream>
#include <vector>
#include <set>
using namespace std;

class CocksMoscow {
private:
    int height;
    int width;
    int size;
    int leftFraction;
    int rightFraction;
    vector<vector<int>> graph;
    vector<int> mt;
    vector<int> used;
    set<int> crossedCellsRight;
    set<int> crossedCellsLeft;

    bool kuhn(int v) {
        if (used[v] != 0) return false;
        used[v] = 1;
        for (int i = 0; i < graph[v].size(); i++) {
            int to = graph[v][i];
            bool ifContinue = false;
            for (int j : crossedCellsRight) {
                if (j == to) {
                    ifContinue = true;
                    break;
                }
            }
            if (ifContinue) continue;
            if (mt[to] == -1 || kuhn(mt[to])) {
                mt[to] = v;
                return true;
            }
        }
        return false;
    }
public:
    CocksMoscow (int height, int width) {
        this->height = height;
        this->width = width;
        this->size = height * width;
        this->leftFraction = size % 2 == 0 ? size / 2 : size / 2 + 1;
        this->rightFraction = size / 2;
        graph.resize(leftFraction);
        mt.assign(rightFraction, -1);
        used.assign(leftFraction, 0);
        for (int i = 0; i < size; i += 2) {
            if (i >= width) {
                graph[i / 2].push_back((i - width) / 2);
            }
            if (i < size - width) {
                graph[i / 2].push_back((i + width) / 2);
            }
            if (i % width > 0) {
                graph[i / 2].push_back((i - 1) / 2);
            }
            if (i % width < width - 1) {
                graph[i / 2].push_back((i + 1) / 2);
            }
        }
    }

    void crossCells() {
        for (int i : crossedCellsLeft) {
            used[i] = 2;
        }
    }

    void addCrossedCell(int w, int h) {
        if ((w * (h - 1) + w) % 2 == 0) {
            crossedCellsRight.insert((w * (h - 1) + w - 1) / 2);
        } else {
            crossedCellsLeft.insert((w * (h - 1) + w - 1) / 2);
        }
    }

    int countCells() {
        int res = 0;
        for (int i = 0; i < leftFraction; i++) {
            used.assign(leftFraction, 0);
            crossCells();
            if (kuhn(i)) res += 2;
        }
        return res;
    }
};

int cocksMoscowMain() {
    int N, M, Q;
    cin >> N >> M >> Q;
    CocksMoscow cocksMoscow(N, M);
    for (int i = 0; i < Q; i++) {
        int w, h;
        cin >> w >> h;
        cocksMoscow.addCrossedCell(w, h);
    }
    cout << cocksMoscow.countCells();
    return 0;
}