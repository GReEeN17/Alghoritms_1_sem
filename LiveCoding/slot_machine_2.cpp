#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 1005;

int reachable_cells;

void dfs(int x_start, int y_start, int steps_left, int steps_right, int x_left, int y_right, char** labyrinth, bool** visited, int n, int m) {

    if (x_start < 0 || x_start >= n || y_start < 0 || y_start >= m || labyrinth[x_start][y_start] == '#' || visited[x_start][y_start]) {
        return;
    }

    if (steps_left > x_left || steps_right > y_right) {
        return;
    }

    visited[x_start][y_start] = true;
    reachable_cells++;

    dfs(x_start-1, y_start, steps_left, steps_right, x_left, y_right, labyrinth, visited, n, m);
    dfs(x_start+1, y_start, steps_left, steps_right, x_left, y_right, labyrinth, visited, n, m);
    dfs(x_start, y_start-1, steps_left+1, steps_right, x_left, y_right, labyrinth, visited, n, m);
    dfs(x_start, y_start+1, steps_left, steps_right+1, x_left, y_right, labyrinth, visited, n, m);
}

int sssss() {
    int n, m;
    cin >> n >> m;
    int x_start, y_start;
    cin >> x_start >> y_start;
    int x_left, y_right;
    cin >> x_left >> y_right;
    char** labyrinth = new char*[n];
    for (int i = 0; i < n; i++) {
        labyrinth[i] = new char[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> labyrinth[i][j];
        }
    }
    bool** visited = new bool*[n];
    for (int i = 0; i < n; i++) {
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }
    dfs(x_start, y_start, 0, 0, x_left, y_right, labyrinth, visited, n, m);
    cout << reachable_cells << endl;
    return 0;
}