#include <iostream>
using namespace std;

void buildTreeFC (int tree[], int mas[], int v, int L, int R, int n) {
    if (L == R - 1) {
        if (L < n) {
            tree[v] = mas[L];
        }
        return;
    }
    int M = (L + R) / 2;
    buildTreeFC(tree, mas, 2 * v + 1, L, M, n);
    buildTreeFC(tree, mas, 2 * v + 2, M, R, n);
    tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
}

int getSumFC (int tree[], int v, int L, int R, int l, int r) {
    if (r <= L || R <= l) return 0;
    if (l <= L && R <= r) return tree[v];
    int M = (L + R) / 2;
    int first_child = getSumFC(tree, 2 * v + 1, L, M, l, r);
    int second_child = getSumFC(tree, 2 * v + 2, M, R, l, r);
    return first_child + second_child;
}

void updateFC(int tree[], int v, int L, int R, int i, int x) {
    if (L == R - 1)
    {
        tree[v] = x;
        return;
    }
    int M = (L + R) / 2;
    if (i < M) updateFC(tree,2 * v + 1, L, M, i, x);
    else updateFC(tree, 2 * v + 2, M, R, i, x);
    tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
}


int main() {
    int n, q;
    cin >> n >> q;
    if (n == 0) {
        return 0;
    }
    char func;
    int digit_1, digit_2;
    int mas[n + 1];
    for (int i = 0; i < n + 1; i++) {
        mas[i] = 0;
    }
    int tree[(n + 1) * 4];
    for (int i = 0; i < (n + 1) * 4; i++) {
        tree[i] = 0;
    }
    buildTreeFC(tree, mas, 0, 0, n + 1, n + 1);
    for (int i = 0; i < q; i++) {
        cin >> func >> digit_1 >> digit_2;
        if (func == '?') {
            cout << getSumFC(tree, 0, 0, n + 1, digit_1 - 1, digit_2) << "\n";
        } else if (func == '+'){
            mas[digit_1] += digit_2;
            updateFC(tree, 0, 0, n + 1, digit_1 - 1, mas[digit_1]);
        } else {
            mas[digit_1] -= digit_2;
            if (mas[digit_1] < 0) {
                mas[digit_1] = 0;
            }
            updateFC(tree, 0, 0, n + 1, digit_1 - 1, mas[digit_1]);
        }
    }
    return 0;
}