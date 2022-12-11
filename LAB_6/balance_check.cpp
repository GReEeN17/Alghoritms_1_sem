#include <iostream>
using namespace std;

void balance(int mas[][3], int height[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        height[i + 1] = 1 + max(height[mas[i][1]], height[mas[i][2]]);
    }
}

int balance_check() {
    int n;
    cin >> n;
    int mas[n][3];
    for (int i = 0; i < n; i++) {
        cin >> mas[i][0] >> mas[i][1] >> mas[i][2];
    }
    int height[n];
    balance(mas, height, n);
    for (int i = 0; i < n; i++) {
        cout << height[mas[i][2]] - height[mas[i][1]] << "\n";
    }
}