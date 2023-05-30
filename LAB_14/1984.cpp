#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#define capacity 5656542342
#define q 256

class Task1984 {
private:
    string name;
    string hymn;
    int sizeName;
    int sizeHymn;
public:
    Task1984(string name, string hymn) {
        this->hymn = std::move(hymn);
        this->name = std::move(name);
        sizeHymn = (int) this->hymn.size();
        sizeName = (int) this->name.size();
    }

    void rabinCarp() {
        int hashName = 0;
        for (int i = 0; i < sizeName; i++) {
            hashName = (hashName * q + name.at(i)) % capacity;
        }
        int hashHymn = 0;
        for (int i = 0; i < sizeName; i++) {
            hashHymn = (hashHymn * q + hymn.at(i)) % capacity;
        }
        int maxIndex = pow(q, sizeName - 1);
        vector<int> res;
        for (int i = 0; i <= (sizeHymn - sizeName); i++) {
            if (hashHymn == hashName) {
                bool isEqual = true;
                for (int j = i; j < (i + sizeName); j++) {
                    if (hymn[j] != name[j - i]) {
                        isEqual = false;
                        break;
                    }
                }
                if (isEqual) res.push_back(i);
            }
            hashHymn = (q * (hashHymn - maxIndex * hymn[i]) + hymn[i + sizeName]) % capacity;
        }
        cout << res.size() << "\n";
        for (int i : res) {
            cout << i << " ";
        }
    }

};

int Sol1984() {
    string hymn, name;
    cin >> hymn >> name;
    Task1984 solution(name, hymn);
    solution.rabinCarp();
    return 0;
}