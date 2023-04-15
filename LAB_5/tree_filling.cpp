#include <iostream>
using namespace std;
int k = 1;

void print_tree(int mas[][3], int n, int ind) {
    ind--;
    if (ind == -1) {
        return;
    }
    print_tree(mas,n, mas[ind][1]);
    mas[ind][0] = k;
    k++;
    print_tree(mas, n, mas[ind][2]);
}

int tree_filling() {
    int n;
    cin >> n;
    int mas[n][3];
    for (int i = 0; i < n; i++) {
        mas[i][0] = i + 1;
        cin >> mas[i][1] >> mas[i][2];
    }
    print_tree(mas, n, 1);
    for (int i = 0; i < n; i++) {
        cout << mas[i][0] << " ";
    }
    return 0;
}
