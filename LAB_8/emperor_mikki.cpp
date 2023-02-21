#include <iostream>
using namespace std;

int main() {
    int n_coeff, q_1_coeff;
    cin >> n_coeff >> q_1_coeff;
    int vertexes_coeff[n_coeff];
    for (int i = 0; i < n_coeff; i++) {
        cin >> vertexes_coeff[i];
    }
    int diff_coeff[q_1_coeff];
    for (int i = 0; i < q_1_coeff; i++) {
        cin >> diff_coeff[i];
    }
    int n_symb, q_2_symb;
    cin >> n_symb >> q_2_symb;
    char vertexes_symb[n_symb];
    for (int i = 0; i < n_symb; i++) {
        cin >> vertexes_symb[i];
    }
    int diff_symb[q_2_symb];
    for (int i = 0; i < q_2_symb; i++) {
        cin >> diff_symb[i];
    }

}