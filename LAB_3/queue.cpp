#include <iostream>

struct cell {
    int val;
    cell* next;
    cell(int _val) : val(_val), next(nullptr) {}
};

struct list_query {
    cell* start;
    cell* end;
    list_query(): start(nullptr), end(nullptr) {}

    bool is_empty() {
        if (start == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    void push_back(int val) {
        cell* u = new cell(val);
        if (is_empty()) {
            start = u;
            end = u;
        } else {
            end->next = u;
            end = u;
        }
    }

    void pop() {
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

int queue() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    std::cin >> n;
    list_query li;
    for (int i = 0; i < n; i++) {
        char inout;
        int elem;
        std::cin >> inout;
        if (inout == '+') {
            std::cin >> elem;
            li.push_back(elem);
        } else {
            li.pop();
        }
    }
    return 0;
}
