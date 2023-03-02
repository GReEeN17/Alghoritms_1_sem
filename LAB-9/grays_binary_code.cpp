#include <iostream>
#include <cmath>
using namespace std;

unsigned int grayen_code(unsigned int g) {
    return g ^ (g >> 1);
}

int grays_binary_code() {
    int n;
    cin >> n;
    unsigned short mas[n];
    for (int i = 0; i < pow(2, n); i++) {
        unsigned int temp = grayen_code(i);
        for (int j = 0; j < n; j++) {
            mas[j] = temp % 2;
            temp /= 2;
        }
        for (int j = n - 1; j >= 0; j--) {
            cout << mas[j];
        }
        cout << "\n";
    }
}