#include <iostream>
using namespace std;

void siftDown(int n, int mas[], int i){
    int left, right, j;
    while (2 * i + 1 < n) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        j = left;
        if (right < n && mas[right] < mas[left]) {
            j = right;
        }
        if (mas[i] <= mas[j]) {
            break;
        }
        swap(mas[i], mas[j]);
        i = j;
    }
}

void buildHeap(int n, int mas[]) {
    for (int i = n / 2; i >= 0; i--) {
        siftDown(n, mas, i);
    }
}

void heapSort(int mas[], int n) {
    buildHeap(n, mas);
    int heapSize = n;
    for (int i = 0; i < n; i++) {
        swap(mas[0], mas[n - i - 1]);
        heapSize--;
        siftDown(heapSize, mas, 0);
    }
}


int pyramid_sort() {
    int n;
    cin >> n;
    int mas[n];
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    heapSort(mas, n);
    for (int i = n - 1; i >= 0; i--) {
        cout << mas[i] << " ";
    }
    return 0;
}