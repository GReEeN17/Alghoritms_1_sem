#include <iostream>
#include <vector>
using namespace std;
#define capacity 2000000

int hashFuncCarnations(int key, int i) {
    return (key + i) % capacity;
}

void insert(int key, vector<int>& hashTable) {
    int x = hashFuncCarnations(key, 0);
    for (int i = 1; i < capacity; i++) {
        if (hashTable[x] == -1) {
            hashTable[x] = key;
            return;
        } else {
            x = hashFuncCarnations(key, i);
        }
    }
}

bool search(int key, vector<int>& hashTable) {
    int x = hashFuncCarnations(key, 0);
    for (int i = 1; i < capacity; i++) {
        if (hashTable[x] == key) {
            return true;
        } else if (hashTable[x] == -1) {
            return false;
        } else {
            x = hashFuncCarnations(key, i);
        }
    }
    return false;
}

int carnations() {
    int N;
    cin >> N;
    vector<int> x(capacity, -1);
    vector<int> y(capacity, -1);
    int res = 0;
    for (int i = 0; i < N; i++) {
        int tempX, tempY;
        cin >> tempX >> tempY;
        if (!search(tempX, x) && !search(tempY, y)) {
            insert(tempX, x);
            insert(tempY, y);
            res++;
        }
    }
    cout << (res == 3 ? "YES" : "NO") << "\n";
    return 0;
}