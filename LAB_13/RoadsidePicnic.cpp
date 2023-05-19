#include <iostream>
#include <vector>
using namespace std;
#define capacity 100001

int hashFuncRoadside(int key) {
    return key % capacity;
}

int roadsidePicnic() {
    int N;
    cin >> N;
    vector<bool> hashTable(capacity, false);
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        hashTable[hashFuncRoadside(temp)] = true;
    }
    int M;
    cin >> M;
    int res = 0, gap_res = 0;
    bool isPrev = false;
    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        if (hashTable[hashFuncRoadside(temp)]) {
            gap_res++;
            isPrev = true;
        } else {
            if (isPrev) {
                res = max(res, gap_res);
            }
            gap_res = 0;
            isPrev = false;
        }
    }
    if (isPrev) {
        res = max(res, gap_res);
    }
    cout << res;
    return 0;
}