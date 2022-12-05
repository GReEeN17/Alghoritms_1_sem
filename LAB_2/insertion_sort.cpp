#include <iostream>

int insertion_sort() {
    int n;
    std::cin >> n;
    int mas[n];
    for (int i = 0; i < n; i++) {
        std::cin >> mas[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j > 0 && mas[j -1] > mas[j]; j--) {
            int gap = mas[j - 1];
            mas[j - 1] = mas[j];
            mas[j] = gap;
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    return 0;
}
