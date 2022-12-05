#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct priorityQue {
    vector<int> massive;
    vector<int> comands;

    void siftDown(int i) {
        int left, right, j;
        int n = massive.size();
        while (2 * i + 1 < n) {
            left = 2 * i + 1;
            right = 2 * i + 2;
            j = left;
            if (right < n && massive[right] < massive[left]) {
                j = right;
            }
            if (massive[i] <= massive[j]) {
                break;
            }
            swap(massive[i], massive[j]);
            i = j;
        }
    }

    void siftUp(int i) {
        while ((i - 1) / 2 >= 0 && massive[i] < massive[(i - 1) / 2]) {
            swap(massive[i], massive[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void push(int val) {
        massive.push_back(val);
        comands.push_back(val);
        siftUp(massive.size() - 1);
    }

    void extractMin() {
        comands.push_back(0);
        if (massive.empty()) {
            cout << "*" << "\n";
        } else {
            int min = massive[0];
            cout << min << "\n";
            swap(massive[0], massive[massive.size() - 1]);
            massive.pop_back();
            siftDown(0);
        }
    }

    void decreaseKey(int x, int y) {
        comands.push_back(0);
        int i;
        for (i = 0; i < massive.size(); i++) {
            if (massive[i] == comands[x - 1]) {
                massive[i] = y;
                break;
            }
        }
        siftUp(i);
        comands[x - 1] = y;
    }
};

int priority_queue() {
    priorityQue pr;
    string s;
    string func;
    int val, x, y;
    while(getline(cin, s)) {
        if (s.empty()) {
            break;
        }
        istringstream iss(s);
        iss >> func;
        if (func == "push") {
            iss >> val;
            pr.push(val);
        } else if (func == "extract-min") {
            pr.extractMin();
        } else {
            iss >> x >> y;
            pr.decreaseKey(x, y);
        }
    }
}