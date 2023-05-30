#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define capacity 1892790
#define k 42

int hashFuncRoadside(int key, int i) {
    int temp = floor(key * pow(k, i));
    return temp % capacity;
}

int roadsidePicnic() {
    int N;
    cin >> N;
    vector<int> hashTable(capacity, 0);
    vector<int> first;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        first.push_back(temp);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            hashTable[hashFuncRoadside(first[j], i)] = first[j];
        }
    }
    int M;
    cin >> M;
    int res = 0;
    for (int i = 0; i < M; i++) {
        int temp = 0;
        cin >> temp;
        if (hashTable[hashFuncRoadside(temp, i)] == temp) {
            res++;
        }
    }
    cout << res;
    return 0;
}