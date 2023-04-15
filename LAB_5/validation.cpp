#include <iostream>
#include <vector>
using namespace std;

bool isBinTree (int mas[][3], int i, int min_elem, int max_elem) {
    if (mas[i][0] > max_elem || mas[i][0] < min_elem) {
        return false;
    }
    if (mas[i][1] == 0 && mas[i][2] == 0) {
        return true;
    }
    if (mas[i][1] != 0 && mas[i][2] != 0){
        return isBinTree(mas, mas[i][1] - 1, min_elem, mas[i][0] - 1) && isBinTree(mas, mas[i][2] - 1, mas[i][0] + 1, max_elem);
    } else if (mas[i][1] == 0) {
        return isBinTree(mas, mas[i][2] - 1, mas[i][0] + 1, max_elem);
    } else if (mas[i][2] == 0) {
        return isBinTree(mas, mas[i][1] - 1, min_elem, mas[i][0] - 1);
    }
    return false;
}

int validation() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    cin >> n;
    int mas[n][3];
    if (n == 0) {
        cout << "YES";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> mas[i][0] >> mas[i][1] >> mas[i][2];
    }
    int min_elem = -1000000001;
    int max_elem = 1000000001;
    bool res;
    res = isBinTree(mas, 0, min_elem, max_elem);
    if (res) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
    return 0;
}
