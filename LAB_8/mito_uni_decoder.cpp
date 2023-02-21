#include <iostream>
#include <cmath>

int mito_decoder() {
    int k;
    std::cin >> k;
    std::string mas[k];
    std::string gap_string;
    for (int i = 0; i < k; i++) {
        std::cin >> mas[i];
    }
    for (int i = 0; i < k; i++) {
        int cur_pow = 0;
        int len = mas[i].length();
        while (len > 0) {
            len /= 2;
            cur_pow++;
        }
        int move = 1, ind = 0;
        int contr_bites[cur_pow];
        for (int j = 0; j < cur_pow; j++) {
            contr_bites[j] = 0;
        }
        while (move < pow(2, cur_pow)) {
            int contr_move = 0;
            for (int j = move - 1; j < mas[i].length(); j++) {
                if (mas[i][j] == '1') {
                    contr_bites[ind]++;
                }
                contr_move++;
                if (contr_move == move) {
                    j += move;
                    contr_move = 0;
                }
            }
            move *= 2; ind++;
        }
        int mstk = 0;
        for (int j = 0; j < cur_pow; j++) {
            if (contr_bites[j] % 2 == 1) {
                mstk += pow(2, j);
            }
        }
        if (mstk > 0) {
            if (mas[i][mstk - 1] == '0') {
                mas[i][mstk - 1] = '1';
            } else {
                mas[i][mstk - 1] = '0';
            }
        }
        std::string res;
        for (int j = 0; j < mas[i].length(); j++) {
            int cpy = j + 1;
            bool is_second_pow;
            while (cpy > 0) {
                if (cpy == 1) {
                    is_second_pow = true;
                    break;
                } else if (cpy % 2 != 0) {
                    is_second_pow = false;
                    break;
                }
                cpy /= 2;
            }
            if (!is_second_pow) {
                res.push_back(mas[i][j]);
            }
        }
        std::cout << res << "\n";
    }
}