#include <iostream>
#include <vector>
using namespace std;
#define k 45

int hash1(string key) {
    int res = 0;
    for (int i = 0; i < key.size(); i++) {
        res += key.at(i) * pow(k, i);
    }
    return res % 10000001;
}

int hash2(string key) {
    int res = 0;
    for (int i = 0; i < key.size(); i++) {
        res += key.at(i) * pow(k, i);
    }
    return res % 9999998;
}

struct Set {
    vector<string> que;
    vector<bool> ch;

    Set() {
        que = vector<string>(10000009, "");
        ch = vector<bool>(10000009, false);
    }

    void insert(string n) {
        int index1 = hash1(n);
        int index2 = hash2(n);
        int count = 0;
        while (count < 100000) {
            if (que[index1] == "" && !ch[index1]) {
                ch[index1] = true;
                return;
            } else if (que[index2] == "" && !ch[index2]) {
                ch[index2] = true;
                return;
            } else {
                swap(que[index1], n);
                index1 = hash1(n);
                index2 = hash2(n);
            }
            count++;
        }
    }

    void remove(string n) {
        int index1 = hash1(n);
        int index2 = hash2(n);
        if (que[index1] == n) {
            ch[index1] = false;
        } else {
            ch[index2] = false;
        }
    }

    bool contains(string n) {
        int index1 = hash1(n);
        int index2 = hash2(n);
        if (que[index1] == n) {
            return true;
        } else if (que[index2] == n) {
            return true;
        }
        return false;
    }
};

int main() {

}

