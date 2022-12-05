#include <iostream>
#include <iomanip>
using namespace std;

void search(double l, double r, double a, int n, double& res) {
    double mas[n];
    mas[0] = a;
    while (r - l > 0.00000001) {
        mas[1] = (l + r) / 2;
        bool more = mas[1] > 0.00000001;
        for (int i = 2; i < n && more; i++) {
            mas[i] = 2 * mas[i - 1] - mas[i - 2] + 2;
            if (mas[i] < 0.00000001) more = false;
        }
        if (more) {
            r = mas[1];
        } else {
            l = mas[1];
        }
    }
    res = mas[n - 1];
}

int garland() {
    int n;
    cin >> n;
    double a;
    cin >> a;
    double res;
    search(0, a, a, n, res);
    cout << setprecision(2) << fixed << res << "\n";
    return 0;
}