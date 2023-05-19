#include <iostream>
using namespace std;
#define capacity 1000000

int hashFunctionSet(int key) {
    return key % capacity;
}

int whatIsSet() {
    int N;
    cin >> N;
    int first[capacity];
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        first[hashFunctionSet(temp)] = temp;
    }
    int check = 0;
    for (int i = 0; i < N; i++) {
        int temp = 0;
        cin >> temp;
        if (first[hashFunctionSet(temp)] == temp) check++;
    }
    cout << (check == N ? "YES" : "NO");
    return 0;
}