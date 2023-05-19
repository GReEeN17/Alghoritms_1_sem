#include <iostream>
#include <vector>
using namespace std;
#define k 40
#define hashFirst 1000037
#define hashSecond 1000039
#define capacity 2000001

int hash1(string key) {
    int res = 0;
    for (int i = 0; i < key.size(); i++) {
        res += key.at(i) * pow(k, i);
    }
    return res % hashFirst;
}

int hash2(string key) {
    int res = 0;
    for (int i = 0; i < key.size(); i++) {
        res += key.at(i) * pow(k, i);
    }
    return res % hashSecond;
}

struct Set {
    vector<string> queFirst;
    vector<bool> chFirst;
    vector<string> queSecond;
    vector<bool> chSecond;

    Set() {
        queFirst = vector<string>(hashSecond, "");
        chFirst = vector<bool>(hashSecond, false);
        queSecond = vector<string>(hashSecond, "");
        chSecond = vector<bool>(hashSecond, false);
    }

    void insertFirst(string n) {
        int index1 = hash1(n);
        int index2 = hash2(n);
        int count = 0;
        while (count < 10000) {
            if (queFirst[index1].empty() && !chFirst[index1]) {
                chFirst[index1] = true;
                queFirst[index1] = n;
                return;
            } else if (queFirst[index2].empty() && !chFirst[index2]) {
                chFirst[index2] = true;
                queFirst[index2] = n;
                return;
            } else {
                swap(queFirst[index1], n);
                index1 = hash1(n);
                index2 = hash2(n);
            }
            count++;
        }
    }

    bool containsFirst(string n) {
        int index1 = hash1(n);
        int index2 = hash2(n);
        if (queFirst[index1] == n) {
            return true;
        } else if (queFirst[index2] == n) {
            return true;
        }
        return false;
    }

    void insertSecond(string n) {
        int index1 = hash1(n);
        int index2 = hash2(n);
        int count = 0;
        while (count < 10000) {
            if (queSecond[index1].empty() && !chSecond[index1]) {
                chSecond[index1] = true;
                queSecond[index1] = n;
                return;
            } else if (queSecond[index2].empty() && !chSecond[index2]) {
                chSecond[index2] = true;
                queSecond[index2] = n;
                return;
            } else {
                swap(queSecond[index1], n);
                index1 = hash1(n);
                index2 = hash2(n);
            }
            count++;
        }
    }

    bool containsSecond(string n) {
        int index1 = hash1(n);
        int index2 = hash2(n);
        if (queSecond[index1] == n) {
            return true;
        } else if (queSecond[index2] == n) {
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    if (N == 0) {
        cout << "0 0 0";
        return 0;
    }
    Set set;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        if (!set.containsFirst(str)) set.insertFirst(str);
    }
    int first = N * 3, second = N * 3, third = N * 3;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        if (set.containsFirst(str)) {
            first -= 2;
            second -= 2;
        }
        if (!set.containsSecond(str)) {
            set.insertSecond(str);
        }
    }
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        if (set.containsFirst(str) && set.containsSecond(str)) {
            --first;
            --second;
            third -= 3;
        } else if (set.containsSecond(str)) {
            second -= 2;
            third -= 2;
        } else if (set.containsFirst(str)) {
            first -= 2;
            third -= 2;
        }
    }
    cout << first << " " << second << " " << third;
    return 0;
}

