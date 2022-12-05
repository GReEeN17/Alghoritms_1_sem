#include <iostream>
#include <sstream>

struct celPN {
    int val;
    celPN* next;
    celPN(int _val) : val(_val), next(nullptr) {}
};

struct listPN {
    celPN* start;
    celPN* end;
    listPN(): start(nullptr), end(nullptr) {}

    bool empty() {
        if (start == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    void push_back(int val) {
        celPN* u = new celPN(val);
        if (empty()) {
            start = u;
            end = u;
        } else {
            u->next = start;
            start = u;
        }
    }

    int return_last() {
        return start->val;
    }

    void withdraw() {
        if (start == end) {
            start = nullptr;
            end = nullptr;
        } else {
            start = start->next;
        }
    }
};

int correct_notation() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    listPN li;
    std::string s;
    getline(std::cin, s);
    std::istringstream iss(s);
    int elem = 0, elem_2 = 0;
    char sym[10];
    while (iss >> sym) {
        if (sym[0] == '+') {
            elem = li.return_last();
            li.withdraw();
            elem_2 = li.return_last();
            li.withdraw();
            li.push_back(elem + elem_2);
        } else if (sym[0] == '-') {
            elem = li.return_last();
            li.withdraw();
            elem_2 = li.return_last();
            li.withdraw();
            li.push_back(elem_2 - elem);
        } else if (sym[0] == '*') {
            elem = li.return_last();
            li.withdraw();
            elem_2 = li.return_last();
            li.withdraw();
            li.push_back(elem * elem_2);
        } else {
            elem = std::stoi(sym);
            li.push_back(elem);
        }
    }
    int res = li.return_last();
    std::cout << res << "\n";
    return 0;
}
