#include <iostream>
using namespace std;

int max_hei(int l, int r) {
    if (l > r) {
        return l;
    } else {
        return r;
    }
}

int height(int mas[][3], int ind_root) {
    ind_root--;
    if (mas[ind_root][1] == 0 && mas[ind_root][2] == 0) {
        return 1;
    } else if (mas[ind_root][1] == 0) {
        return 1 + height(mas, mas[ind_root][2]);
    } else if (mas[ind_root][2] == 0) {
        return 1 + height(mas, mas[ind_root][1]);
    } else {
        return 1 + max_hei(height(mas, mas[ind_root][1]), height(mas, mas[ind_root][2]));
    }
}

int tree_height() {
    int n;
    cin >> n;
    int mas[n][3];
    for (int i = 0; i < n; i++) {
        cin >> mas[i][0] >> mas[i][1] >> mas[i][2];
    }
    if (n == 0) {
        cout << 0;
    } else {
        int res = height(mas, 1);
        cout << res;
        return 0;
    }
    return 0;
}