#include <iostream>
#include <map>
using namespace std;

class JuniorLibrarian {
private:
    struct BORElement{
        int count = 0;
        int wordCount = 0;
        bool isTerminal = false;
        map<char, BORElement*> next = {};
    };
    BORElement* root;
    int total = 0;
public:
    JuniorLibrarian() {
        root = new BORElement;
    }

    void insertBook(const string& book) {
        BORElement* cur = root;
        for (char i : book) {
            if (cur->next.find(i) == cur->next.end()) cur->next[i] = new BORElement;
            cur = cur->next[i];
            cur->count++;
        }
        cur->wordCount++;
        cur->isTerminal = true;
        total++;
    }

    void findBook(int id) {
        BORElement* cur = root;
        string res;
        int curId = 0;
        while (curId < id) {
            for (auto i : cur->next) {
                if (curId + i.second->count < id) {
                    curId += i.second->count;
                } else {
                    res.push_back(i.first);
                    cur = i.second;
                    if (cur->isTerminal) curId += cur->wordCount;
                    break;
                }
            }
        }
        cout << res << "\n";
    }
};

int juniorLibrarian() {
    int N;
    cin >> N;
    JuniorLibrarian jun;
    for (int i = 0; i < N; i++) {
        string req;
        cin >> req;
        if (req[0] >= 'a' && req[0] <= 'z') {
            jun.insertBook(req);
        } else {
            int id = stoi(req);
            jun.findBook(id);
        }
    }
    return 0;
}