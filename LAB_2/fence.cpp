#include <iostream>
#include <vector>

void mergeF(int left, int right, int mid, int mas[]) {
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

void mergeSortRecursiveF(int mas[], int left, int right) {
    if (left + 1 >= right) {
        return;
    }
    int mid = (left + right) / 2;
    mergeSortRecursiveF(mas, left, mid);
    mergeSortRecursiveF(mas, mid, right);
    mergeF(left, right, mid, mas);
}

int fence() {
    int n;
    std::cin >> n;
    int mas_left[n], mas_right[n];
    for (int i = 0; i < n; i++) {
        std::cin >> mas_left[i];
        std::cin >> mas_right[i];
    }
    mergeSortRecursiveF(mas_left, 0, n);
    mergeSortRecursiveF(mas_right, 0, n);
    int res = mas_right[0] - mas_left[0] + 1;
    for (int i = 1; i < n; i++) {
        if (mas_left[i] - mas_right[i - 1] < 2) {
            res += mas_right[i] - mas_right[i - 1];
        } else {
            res += mas_left[i] - mas_right[i] + 1;
        }
    }
    std::cout << res;
    return 0;
}