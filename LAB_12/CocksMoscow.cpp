#include <iostream>
#include <vector>
using namespace std;

class CocksMoscow {
private:
    int height;
    int width;
    vector<vector<bool>> field;
    vector<vector<bool>> used;
    vector<vector<pair<int, int>>> match;

    bool dfs(int first, int second) {
        if (used[first][second]) return false;
        used[first][second] = true;
        vector<pair<int, int>> neigh;
        if (first > 0 && field[first - 1][second]) {
            neigh.push_back({first - 1, second});
        }
        if (first < height - 1 && field[first + 1][second]) {
            neigh.push_back({first + 1, second});
        }
        if (second > 0 && field[first][second - 1]) {
            neigh.push_back({first, second - 1});
        }
        if (second < width - 1 && field[first][second + 1]) {
            neigh.push_back({first, second + 1});
        }
        for (auto iter : neigh) {
            int f = iter.first;
            int s = iter.second;
            if (match[f][s] == pair<int, int>{-1, -1} || dfs(match[f][s].first, match[f][s].second)) {
                match[f][s] = {first, second};
                return true;
            }
        }
        return false;
    }
public:
    CocksMoscow(int N, int M) {
        height = N;
        width = M;
        field.resize(N, vector<bool>(M, true));
        used.resize(N, vector<bool>(M, false));
        match.resize(N, vector<pair<int, int>>(M, {-1, -1}));
    }

    void crossCell(int h, int w) {
        field[h][w] = false;
    }

    int kuhn() {
        int res = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (field[i][j]) {
                    used.assign(height, vector<bool>(width, false));
                    if (dfs(i, j)) res++;
                }
            }
        }
        return res;
    }
};

int cocksMoscow() {
    int N, M, Q;
    cin >> N >> M >> Q;
    CocksMoscow matching(N, M);
    for (int i = 0; i < Q; i++) {
        int height, width;
        cin >> height >> width;
        matching.crossCell(height - 1, width - 1);
    }
    cout << matching.kuhn();
    return 0;
}