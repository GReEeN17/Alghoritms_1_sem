#include <iostream>
#include <vector>
using namespace std;
#define capacity 10000000

int hashFuncBAB(int key) {
    return (key + capacity) % capacity;
}

int BAB() {
    int N;
    cin >> N;
    vector<int> hashTable(capacity, 0);
    int res = 0;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        int index = hashFuncBAB(temp - i);
        if (hashTable[index] == 0) {
            hashTable[index] = hashTable[index] + 1;
        } else if (hashTable[index] != 0) {
            res += hashTable[index];
            hashTable[index] = hashTable[index] + 1;
        }
    }
    cout << res;
    return 0;
}