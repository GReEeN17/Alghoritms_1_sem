#include <iostream>

struct cellM {
    int val;
    cellM* next;
    cellM(int _val) : val(_val), next(nullptr) {}
};

struct max_list {
    cellM* start;
    cellM* end;
    cellM* start_max;
    cellM* end_max;
    max_list(): start(nullptr), end(nullptr), start_max(nullptr), end_max(nullptr) {}

    bool max_empty() {
        if (start == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    void max_push_back(int val) {
        cellM* u = new cellM(val);
        if (max_empty()) {
            start = u;
            end = u;
            start_max = u;
            end_max = u;
        } else {
            u->next = start;
            start = u;
            cellM* buff = new cellM(0);
            if (val > start_max->val) {
                buff->val = val;
            } else {
                buff->val = start_max->val;
            }
            buff->next = start_max;
            start_max = buff;
        }
    }

    void max_withdraw() {
        if (start == end) {
            start = nullptr;
            end = nullptr;
        } else {
            start = start->next;
            start_max = start_max->next;
        }
    }

    void max_find() {
        std::cout << start_max->val << "\n";
    }
};

int maxstack() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    std::cin >> n;
    max_list li;
    char inout[4];
    int elem;
    for (int i = 0; i < n; i++) {
        std::cin >> inout;
        if (inout[0] == '+') {
            std::cin >> elem;
            li.max_push_back(elem);
        } else if (inout[0] == '-'){
            li.max_withdraw();
        } else {
            li.max_find();
        }
    }
    return 0;
}
