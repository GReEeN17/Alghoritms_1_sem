#include <iostream>
using namespace std;

int Left(int mas[], int key, int size) {
    int l = 0;
    int r = size - 1;
    int res = -1;
    int mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (key < mas[mid]) {
            r = mid - 1;
        } else if (key > mas[mid]) {
            l = mid + 1;
        } else {
            res = mid;
            r = mid - 1;
        }
    }
    return res == -1 ? res : res + 1;
}

int Right(int mas[], int key, int size) {
    int l = 0;
    int r = size - 1;
    int res = -1;
    int mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (key < mas[mid]) {
            r = mid - 1;
        } else if (key > mas[mid]) {
            l = mid + 1;
        } else {
            res = mid;
            l = mid + 1;
        }
    }
    return res == -1 ? res : res + 1;
}

int binary_search() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int mas[n];
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    int m;
    cin >> m;
    int mas_commands[m];
    for (int i = 0; i < m; i++) {
        cin >> mas_commands[i];
    }
    int key, l = 0, r = n - 1, mid = 0;
    bool flag;
    int left_border, right_border;
    for (int i = 0; i < m; i++) {
        flag = false;
        l = 0;
        r = n - 1;
        key = mas_commands[i];
        left_border = Left(mas, key, n);
        right_border = Right(mas, key, n);
        cout << left_border << ' ' << right_border << "\n";
    }
}
