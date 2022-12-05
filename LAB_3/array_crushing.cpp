#include <iostream>
#include <vector>
using namespace std;

void splitter(long long mas[], int k, long long l, long long r, int n) {
    int amount_of_partition;
    while (l + 1 < r) {
        amount_of_partition = 0;
        long long mid = (l + r) / 2;
        long long sum_gap = 0;
        for (int i = 0; i < n; i++) {
            if (mas[i] + sum_gap > mid) {
                amount_of_partition++;
                sum_gap = mas[i];
            } else {
                sum_gap += mas[i];
            }
        }
        if (amount_of_partition >= k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    long long sum_min = l + 1;
    amount_of_partition = 0;
    long long sum_gap = 0;
    bool res[n];
    for (int i = 0; i < n; i++) res[i] = false;
    for (int i = 0; i < n; i++) {
        if (sum_gap + mas[i] > sum_min) {
            amount_of_partition++;
            sum_gap = mas[i];
            res[i] = true;
        } else {
            sum_gap += mas[i];
        }
    }
    for (int i = 1; (i < n) && (amount_of_partition < k - 1); i++) {
        if (!res[i]) {
            res[i] = true;
            amount_of_partition++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (res[i]) {
            cout << i << " ";
        }
    }
}

int array_crushing() {
    int n, k;
    cin >> n >> k;
    long long mas[n];
    long long max_elem = -1, sum_of_elems = 0;
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
        if (mas[i] > max_elem) max_elem = mas[i];
        sum_of_elems += mas[i];
    }
    splitter(mas, k, max_elem - 1, sum_of_elems, n);
    return 0;
}
