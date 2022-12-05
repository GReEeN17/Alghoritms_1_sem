#include <iostream>

int results_of_olimpiade() {
    int n;
    std::cin >> n;
    int mas_ids[n], mas_points[n];
    for (int i = 0; i < n; i++) {
        std::cin >> mas_ids[i];
        std::cin >> mas_points[i];
    }
    int res_ids[n], res_points[n];
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && mas_points[j - 1] < mas_points[j]; j--) {
            std::swap(mas_points[j - 1], mas_points[j]);
            std::swap(mas_ids[j - 1], mas_ids[j]);
        }
    }
    for (int i = 1; i < n; i++){
        for (int j = i; j > 0 && mas_points[j - 1] == mas_points[j] && mas_ids[j - 1] > mas_ids[j]; j--) {
            std::swap(mas_points[j - 1], mas_points[j]);
            std::swap(mas_ids[j - 1], mas_ids[j]);
        }
    }
    for (int i = 0; i < n; i++){
        std::cout << mas_ids[i] << " " << mas_points[i] << "\n";
    }
    return 0;
}


