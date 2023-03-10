#include <iostream>
#include <vector>
using namespace std;

void adj_comp(char **matrix, int i, int j) {
    matrix[i][j] = '#';
    if (matrix[i + 1][j] == '.') {
        adj_comp(matrix, i + 1, j);
    }
    if (matrix[i][j + 1] == '.') {
        adj_comp(matrix, i, j + 1);
    }
    if (matrix[i - 1][j] == '.') {
        adj_comp(matrix, i - 1, j);
    }
    if (matrix[i][j - 1] == '.') {
        adj_comp(matrix, i, j - 1);
    }
}

int ivans_apartment() {
    int n, m;
    cin >> n >> m;
    //char matrix[n][m];
    char **matrix = new char*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new char[m];
    }
    int res = 0;
    string temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (int j = 0; j < m; j++) {
            matrix[i][j] = temp[j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '.') {
                adj_comp(matrix, i, j);
                res++;
            }
        }
    }
    cout << res << "\n";
    return 0;
}