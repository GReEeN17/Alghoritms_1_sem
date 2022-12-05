#include <iostream>
#include <vector>

void mergeSM(int left, int right, int mid, int mas[]) {
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

void mergeSortRecursiveSM(int mas[], int left, int right) {
    if (left + 1 >= right) {
        return;
    }
    int mid = (left + right) / 2;
    mergeSortRecursiveSM(mas, left, mid);
    mergeSortRecursiveSM(mas, mid, right);
    mergeSM(left, right, mid, mas);
}

int same_massives() {
    int n, m;
    std::cin >> n;
    int mas_1[n];
    for (int i = 0; i < n; i++) {
        std::cin >> mas_1[i];
    }
    std::cin >> m;
    int mas_2[m];
    for (int i = 0; i < m; i++) {
        std::cin >> mas_2[i];
    }
    mergeSortRecursiveSM(mas_1, 0, n);
    mergeSortRecursiveSM(mas_2, 0, m);
    std::vector<int> res_1;
    std::vector<int> res_2;
    res_1.push_back(mas_1[0]);
    int elem = mas_1[0];
    for (int i = 1; i < n; i++) {
        if (elem != mas_1[i]) {
            elem = mas_1[i];
            res_1.push_back(elem);
        }
    }
    res_2.push_back(mas_2[0]);
    elem = mas_2[0];
    for (int i = 0; i < m; i++) {
        if (elem != mas_2[i]) {
            elem = mas_2[i];
            res_2.push_back(elem);
        }
    }
    if (res_1 == res_2) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}