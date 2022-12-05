#include <iostream>
#include <string>
using namespace std;

struct celCBS {
    char val;
    celCBS* next;
    celCBS(int _val) : val(_val), next(nullptr) {}
};

struct brackets_listCBS {
    celCBS* start;
    celCBS* end;
    brackets_listCBS(): start(nullptr), end(nullptr) {}

    bool empty() {
        if (start == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    void push_back(char val) {
        celCBS* u = new celCBS(val);
        if (empty()) {
            start = u;
            end = u;
        } else {
            u->next = start;
            start = u;
        }
    }

    void withdraw() {
        if (start == end) {
            start = nullptr;
            end = nullptr;
        } else {
            start = start->next;
        }
    }

    char return_last() {
        return start->val;
    }
};

int correct_bracket_sequence() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    char elem;
    bool flag;
    int count_open = 0, count_close = 0;
    while(getline(cin, s)) {
        brackets_listCBS li;
        if (s.empty()) {
            break;
        }
        count_open = 0, count_close = 0;
        flag = true;
        int size = s.size();
        for (int i = 0; i < size; i++) {
            if (s[i] == '(' || s[i] == '[') {
                li.push_back(s[i]);
                count_open++;
            } else {
                if (li.empty()){
                    flag = false;
                    break;
                }
                elem = li.return_last();
                count_close++;
                if ((elem == '(' and s[i] == ')') ||(elem == '[' and s[i] == ']')) {
                    li.withdraw();
                } else {
                    flag = false;
                    break;
                }
            }
        }
        if (flag && count_open == count_close) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}
