#include <iostream>
using namespace std;
int resss = 1;

void search_slot_machine(char** graph, int start_x, int start_y, int x_left, int y_right, int n, int m) {
    graph[start_x][start_y] = '#';
    if (start_x + 1 < n && graph[start_x + 1][start_y] != '#') {
        resss++;
        search_slot_machine(graph, start_x + 1, start_y, x_left, y_right, n, m);
    }
    if (start_x - 1 >= 0 && graph[start_x - 1][start_y] != '#') {
        resss++;
        search_slot_machine(graph, start_x - 1, start_y, x_left, y_right, n, m);
    }
    if (start_y + 1 < m && y_right > 0 && graph[start_x][start_y + 1] != '#') {
        resss++;
        search_slot_machine(graph, start_x, start_y + 1, x_left, y_right - 1, n, m);
    }
    if (start_y - 1 >= 0 && x_left > 0 && graph[start_x][start_y - 1] != '#') {
        resss++;
        search_slot_machine(graph, start_x, start_y - 1, x_left - 1, y_right, n, m);
    }
}

int slot_machine() {
    int n, m;
    cin >> n >> m;
    if (n == 0 || m == 0) {
        cout << 0;
        return 0;
    }
    int x_start, y_start;
    cin >> x_start >> y_start;
    int x_restrict, y_restrict;
    cin >> x_restrict >> y_restrict;
    char** labyrinth = new char*[n];
    for (int i = 0; i < n; i++) {
        labyrinth[i] = new char[m];
    }
    int count_dots = 0;
    char symb;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> symb;
            if (symb == '.') {
                count_dots++;
            }
            labyrinth[i][j] = symb;
        }
    }
    if (labyrinth[x_start][y_start] == '#') {
        cout << 0;
        return 0;
    }
    if (count_dots == 0) {
        cout << 0;
        return 0;
    }
    if (x_start >= n || y_start >= m || x_start < 0 || y_start < 0) {
        cout << 1;
        return 0;
    }
    search_slot_machine(labyrinth, x_start, y_start, x_restrict, y_restrict, n, m);
    cout << resss << "\n";
    return 0;
}