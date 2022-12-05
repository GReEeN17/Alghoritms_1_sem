#include <iostream>

int insert_digit() {
    int n;
    std::cin >> n;
    int mas[n];
    for (int i = 0; i < n; i++) {
        std::cin >> mas[i];
    }
    int ch, pl, boool = 0;
    std::cin >> ch;
    std::cin >> pl;
    int res_mas[n + 1];
    for (int i = 0; i < n + 1; i++) {
        if (i + 1 != pl) {
            res_mas[i] = mas[i - boool];
        } else {
            res_mas[i] = ch;
            boool = 1;
        }
    }
    for (int i = 0; i < n + 1; i++) {
        std::cout << res_mas[i] << " ";
    }
    return 0;
}
