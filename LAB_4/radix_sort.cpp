#include <iostream>
#include <string>
#include <vector>
using namespace std;

int digit(string phrase, int i, int m) {
    char letter = phrase[m - i];
    int dig = letter - 'a';
    return dig;
}

void radixSort(string mas[], int n, int m, int k) {
    int base = 26;
    for (int i = 1; i <= m; i++) {
        int gap_mas[base];
        string res_mas[n];
        for (int j = 0; j < base; j++) {
            gap_mas[j] = 0;
        }
        int d;
        for (int j = 0; j < n; j++) {
            d = digit(mas[j], i, m);
            gap_mas[d]++;
        }
        int count = 0, temp;
        for (int j = 0; j < base; j++) {
            temp = gap_mas[j];
            gap_mas[j] = count;
            count += temp;
        }
        for (int j = 0; j < n; j++) {
            d = digit(mas[j], i, m);
            res_mas[gap_mas[d]] = mas[j];
            gap_mas[d]++;
        }
        for (int j = 0; j < n; j++) {
            mas[j] = res_mas[j];
        }
        if (i == k) {
            for (int j = 0; j < n; j++) {
                cout << mas[j] << "\n";
            }
            exit(0);
        }
    }
}

int radix_sort() {
    int n, m, k;
    cin >> n >> m >> k;
    string mas[n];
    string temp;
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    radixSort(mas, n, m, k);
    for (int i = 0; i < n; i++) {
        cout << mas[i] << "\n";
    }
    return 0;
}