#include <iostream>
using namespace std;

int is_it_a_pyramid() {
    int n;
    cin >> n;
    int mas[n+1];
    for (int i = 1; i < n; i++) {
        cin >> mas[i];
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (2 * i < n) {
            if (mas[i] > mas[2 * i]) {
                flag = false;
                break;
            }
        }
        if (2 * i + 1 < n) {
            if (mas[i] > mas[2 * i + 1]) {
                flag = false;
                break;
            }
        }
    }
    if (flag) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
