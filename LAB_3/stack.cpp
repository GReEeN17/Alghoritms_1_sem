#include <iostream>

struct cel {
    int val;
    cel* next;
    cel(int _val) : val(_val), next(nullptr) {}
};

struct list {
    cel* start;
    cel* end;
    list(): start(nullptr), end(nullptr) {}

    bool empty() {
        if (start == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    void push_back(int val) {
        cel* u = new cel(val);
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
            std::cout << start->val << "\n";
            start = nullptr;
            end = nullptr;
        } else {
            std::cout << start->val << "\n";
            start = start->next;
        }
    }
};

int stack() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    std::cin >> n;
    list li;
    for (int i = 0; i < n; i++) {
        char inout;
        int elem;
        std::cin >> inout;
        if (inout == '+') {
            std::cin >> elem;
            li.push_back(elem);
        } else {
            li.withdraw();
        }
    }
    return 0;
}
