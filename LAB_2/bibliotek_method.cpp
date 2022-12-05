#include <iostream>

int bibliotek_method() {
    int n;
    std::cin >> n;
    int mas[n];
    for (int i = 0; i < n; i++) {
        std::cin >> mas[i];
    }
    int boool = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j > 0 && mas[j -1] > mas[j]; j--) {
            int gap = mas[j - 1];
            mas[j - 1] = mas[j];
            mas[j] = gap;
            boool++;
        }
        if (boool) {
            for (int j = 0; j < n; j ++) {
                std::cout << mas[j] << " ";
            }
            std::cout << "\n";
        }
        boool = 0;
    }
    return 0;
}

