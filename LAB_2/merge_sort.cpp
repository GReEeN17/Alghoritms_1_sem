#include <iostream>

void merge(int left, int right, int mid, int mas[]) {
    int it_1 = 0, it_2 = 0;
    int result[right - left];
    while (left + it_1 < mid && mid + it_2 < right) {
        if (mas[left + it_1] < mas[mid + it_2]) {
            result[it_1 + it_2] = mas[left + it_1];
            it_1++;
        } else {
            result[it_1 + it_2] = mas[mid + it_2];
            it_2++;
        }
    }
    while (left + it_1 < mid) {
        result[it_1 + it_2] = mas[left + it_1];
        it_1++;
    }
    while (mid + it_2 < right) {
        result[it_1 + it_2] = mas[mid + it_2];
        it_2++;
    }
    for (int i = 0; i < it_2 + it_1; i++) {
        mas[left + i] = result[i];
    }
}

void mergeSortRecursive(int mas[], int left, int right) {
    if (left + 1 >= right) {
        return;
    }
    int mid = (left + right) / 2;
    mergeSortRecursive(mas, left, mid);
    mergeSortRecursive(mas, mid, right);
    merge(left, right, mid, mas);
}

int merge_sort() {
    int n;
    std::cin >> n;
    int mas[n];
    for (int i = 0; i < n; i++) {
        std::cin >> mas[i];
    }
    mergeSortRecursive(mas, 0, n);
    for (int i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    return 0;
};

