#include <iostream>
#include <vector>
using namespace std;

void adj_comp(vector<vector<char>> &matrix, int i, int j) {
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

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix;
    int res = 0;
    string temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        matrix.emplace_back();
        for (int j = 0; j < m; j++) {
            matrix[i].push_back(temp[j]);
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