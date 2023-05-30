#include <iostream>
using namespace std;

int lianaKlubina() {
    int N, M;
    cin >> N >> M;
    string text;
    cin >> text;
    int res = 0;
    for (int i = 0; i < M; i++) {
        int first, second, len;
        cin >> first >> second >> len;
        bool isEqual = true;
        for (int j = 0; j < len; j++) {
            if (text[first + j - 1] != text[second + j - 1]) {
                isEqual = false;
                break;
            }
        }
        if (isEqual) res++;
    }
    cout << res;
    return 0;
}