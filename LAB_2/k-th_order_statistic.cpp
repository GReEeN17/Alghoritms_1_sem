#include <iostream>
#include <mm_malloc.h>
using namespace std;

void kth (int *mas, int l, int r, int k) {
    if (l >= r) {
        return;
    } else {
        int mid = mas[(l + r) / 2];
        int left = l, right = r;
        while (left <= right) {
            while (mas[left] < mid) {
                left++;
            }
            while (mas[right] > mid) {
                right--;
            }
            if (left <= right) {
                swap(mas[left], mas[right]);
                left++;
                right--;
            }
        }
        if (k <= right) {
            kth(mas, l, right, k);
        } else {
            kth(mas, left, r, k);
        }
    }
}

int kth_order_statistic() {
    int n, k;
    int a, b, c, mas_1, mas_2;
    cin >> n >> k;
    cin >> a >> b >> c >> mas_1 >> mas_2;
    int *mas = (int*)malloc(sizeof(int) * n);
    mas[0] = mas_1, mas[1] = mas_2;
    for (int i = 2; i < n; i++) {
        mas[i] = a * mas[i - 2] + b * mas[i - 1] + c;
    }
    kth(mas, 0, n - 1, k - 1);
    cout << mas[k - 1];
}