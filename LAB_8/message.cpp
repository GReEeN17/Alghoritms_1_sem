#include <iostream>

int mistakes (std::string fir, std::string sec) {
    int mistake = 0;
    int i = 0, j = 0;
    int cnt_fir = 0, cnt_sec = 0;
    int ind_fir = 1, ind_sec = 1;
    char symb_fir = ' ', symb_sec = ' ';
    while (ind_fir < fir.length() || ind_sec < sec.length()) {
        if (cnt_fir == 0) {symb_fir = fir[i];}
        if (cnt_sec == 0) {symb_sec = sec[j];}
        if (cnt_fir == 0) {
            ind_fir = i + 1;
            while (ind_fir < fir.length() && fir[ind_fir] <= '9' && fir[ind_fir] >= '0') {
                cnt_fir *= 10;
                cnt_fir += (fir[ind_fir] - '0');
                ind_fir++;
                i++;
            }
            i++;
        }
        if (cnt_sec == 0) {
            ind_sec = j + 1;
            while (ind_sec < sec.length() && sec[ind_sec] <= '9' && sec[ind_sec] >= '0') {
                cnt_sec *= 10;
                cnt_sec += (sec[ind_sec] - '0');
                ind_sec++;
                j++;
            }
            j++;
        }
        if (symb_sec != symb_fir) {mistake += std::min(cnt_fir, cnt_sec);}
        int cpy_fir = cnt_fir;
        if (cnt_fir > cnt_sec) {cnt_fir -= cnt_sec;}
        else {cnt_fir = 0;}
        if (cnt_sec > cpy_fir) {cnt_sec -= cpy_fir;}
        else {cnt_sec = 0;}
    }
    return mistake;
}

int main() {
    int n, m, k;
    std::string fir, sec;
    std::cin >> n >> m >> k >> fir >> sec;
    int mistake = mistakes(fir, sec);
    mistake < k? std::cout << "YES" : std::cout << "NO";
    return 0;
}