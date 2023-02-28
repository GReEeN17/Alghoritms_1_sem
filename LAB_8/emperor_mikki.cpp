#include <iostream>
#include <vector>
using namespace std;

struct coeff_node {
    int val;
    coeff_node* left = nullptr;
    coeff_node* right = nullptr;
    coeff_node* parent = nullptr;
};

struct symb_node{
    char val;
    symb_node* left = nullptr;
    symb_node* right = nullptr;
    symb_node* parent = nullptr;
};

void postorder_coeff(coeff_node* gap_node, vector<int>& mas_coeff) {
    if (gap_node != nullptr) {
        postorder_coeff(gap_node->left, mas_coeff);
        postorder_coeff(gap_node->right, mas_coeff);
        mas_coeff.push_back(gap_node->val);
    }
}

void postorder_symb(symb_node* gap_node, vector<char>& mas_symb) {
    if (gap_node != nullptr) {
        postorder_symb(gap_node->left, mas_symb);
        postorder_symb(gap_node->right, mas_symb);
        mas_symb.push_back(gap_node->val);
    }
}

int main() {
    int n_coeff, q_1_coeff;
    cin >> n_coeff >> q_1_coeff;
    coeff_node* vertexes_coeff[n_coeff];
    for (int i = 0; i < n_coeff; i++) {
        auto *gap_node = new coeff_node;
        cin >> gap_node->val;
        vertexes_coeff[i] = gap_node;
        if (i != 0) {
            gap_node->parent = vertexes_coeff[(i - 1) / 2];
            if (i % 2 == 1) {
                gap_node->parent->left = gap_node;
            } else if (i % 2 == 0) {
                gap_node->parent->right = gap_node;
            }
        }
    }
    int temp;
    coeff_node* root_coeff = vertexes_coeff[0];
    for (int i = 0; i < q_1_coeff; i++) {
        cin >> temp;
        coeff_node* root_node = vertexes_coeff[temp - 1];
        coeff_node* parent;
        if (root_node->parent != nullptr) {
            parent = root_node->parent;
            if (root_node->parent->left == root_node) {
                parent->left = root_node->left;
                if (root_node->left != nullptr) root_node->left->parent = parent;
                root_node->left = parent;
                root_node->parent = parent->parent;
                parent->parent = root_node;
                if (root_node->parent != nullptr) {
                    if (root_node->parent->left == parent) root_node->parent->left = root_node;
                    if (root_node->parent->right == parent) root_node->parent->right = root_node;
                }
            } else if (root_node->parent->right == root_node) {
                parent->right = root_node->right;
                if (root_node->right != nullptr) root_node->right->parent = parent;
                root_node->right = parent;
                root_node->parent = parent->parent;
                parent->parent = root_node;
                if (root_node->parent != nullptr) {
                    if (root_node->parent->left == parent) root_node->parent->left = root_node;
                    else if (root_node->parent->right == parent) root_node->parent->right = root_node;
                }
            }
            if (parent == root_coeff) {
                root_coeff = root_node;
            }
        }
    }
    int n_symb, q_2_symb;
    cin >> n_symb >> q_2_symb;
    symb_node* vertexes_symb[n_symb];
    for (int i = 0; i < n_symb; i++) {
        auto* gap_node = new symb_node;
        cin >> gap_node->val;
        vertexes_symb[i] = gap_node;
        if (i != 0) {
            gap_node->parent = vertexes_symb[(i - 1) / 2];
            if ( i % 2 == 1) {
                gap_node->parent->left = gap_node;
            } else if (i % 2 == 0) {
                gap_node->parent->right = gap_node;
            }
        }
    }
    symb_node* root_symb = vertexes_symb[0];
    for (int i = 0; i < q_2_symb; i++) {
        cin >> temp;
        symb_node* s_node = vertexes_symb[temp - 1];
        symb_node* parent;
        if (s_node->parent != nullptr) {
            parent = s_node->parent;
            if (s_node->parent->left == s_node) {
                parent->left = s_node->left;
                if (s_node->left != nullptr) s_node->left->parent = parent;
                s_node->left = parent;
                s_node->parent = parent->parent;
                parent->parent = s_node;
                if (s_node->parent != nullptr) {
                    if (s_node->parent->left == parent) s_node->parent->left = s_node;
                    if (s_node->parent->right == parent) s_node->parent->right = s_node;
                }
            } else if (s_node->parent->right == s_node) {
                parent->right = s_node->right;
                if (s_node->right != nullptr) s_node->right->parent = parent;
                s_node->right = parent;
                s_node->parent = parent->parent;
                parent->parent = s_node;
                if (s_node->parent != nullptr) {
                    if (s_node->parent->left == parent) s_node->parent->left = s_node;
                    else if (s_node->parent->right == parent) s_node->parent->right = s_node;
                }
            }
            if (parent == root_symb) {
                root_symb = s_node;
            }
        }
    }
    vector<int> mas_coeff;
    vector<char> mas_symb;
    postorder_coeff(root_coeff, mas_coeff);
    postorder_symb(root_symb, mas_symb);
    for (int i = 0; i < n_coeff; i++) {
        string gap_line(mas_coeff[i], mas_symb[i]);
        cout << gap_line;
    }
}