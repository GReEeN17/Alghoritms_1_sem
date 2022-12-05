#include <iostream>
using namespace std;

void anti_quickSort(int mas[], int size) {
    for (int i = 2; i < size; i++) {
        swap(mas[i], mas[i / 2]);
    }
}

int anti_quick_sort() {
    int n;
    cin >> n;
    int mas[n];
    for (int i = 0; i < n; i++) {
        mas[i] = i + 1;
    }
    anti_quickSort(mas, n);
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }
}