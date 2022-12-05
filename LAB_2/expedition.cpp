#include <iostream>

void Sort(int* mas, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j > 0 && mas[j -1] > mas[j]; j--) {
            int gap = mas[j - 1];
            mas[j - 1] = mas[j];
            mas[j] = gap;
        }
    }
}

int expedition() {
    int n, m;
    std::cin >> n;
    std::cin >> m;
    int mas_plot[n * m];
    for (int i = 0; i < (n * m); i++) {
        std::cin >> mas_plot[i];
    }
    int k;
    std::cin >> k;
    int mas_misk[k];
    for (int i = 0; i < k; i++) {
        std::cin >> mas_misk[i];
    }
    Sort(mas_plot, n * m);
    Sort(mas_misk, k);
    int res = 0;
    for (int i = 0; i < n * m; i++) {
        for (int j = 0; j < k; j++) {
            if (mas_misk[j] <= mas_plot[i] and mas_misk[j] != 0 and mas_plot[i] != 0) {
                res++;
                mas_plot[i] = 0;
                mas_misk[j] = 0;
            }
        }
    }
    std::cout << res;
    return 0;
}
