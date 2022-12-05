#include <iostream>

int partition(int mas[], int left, int right) {
    int elem = mas[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (mas[i] < elem) {
            i++;
        }
        while (mas[j] > elem) {
            j--;
        }
        if (i >= j) {
            break;
        }
        std::swap(mas[i++], mas[j--]);
    }
    return j;
}

void quicksort(int mas[], int left, int right) {
    if (left < right) {
        int q = partition(mas, left, right);
        quicksort(mas, left, q);
        quicksort(mas, q + 1, right);
    }
}

int quick_sort() {
    int n;
    std::cin >> n;
    int mas[n];
    for (int i = 0; i < n; i++) {
        std::cin >> mas[i];
    }
    quicksort(mas, 0, n - 1);
    for (int i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    return 0;
}