#include <iostream>
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

void make_rotate_coeff(coeff_node* root_node) {
    if (root_node->parent == nullptr) {
        return;
    }
    if (root_node->parent->left == root_node) {
        coeff_node gap_node = *root_node;
        root_node->left = gap_node.parent;
        root_node->parent = gap_node.parent->parent;
        if (root_node->parent) root_node->parent->left = root_node;
        root_node->left->parent = root_node;
        root_node->left->left = gap_node.left;
    } else if (root_node->parent->right == root_node) {
        coeff_node gap_node = *root_node;
        root_node->right = gap_node.parent;
        root_node->parent = gap_node.parent->parent;
        if (root_node->parent) root_node->parent->right = root_node;
        root_node->right->parent = root_node;
        root_node->right->right = gap_node.right;
    }
}

void make_rotate_symb(symb_node* root_node) {
    if (root_node->parent == nullptr) {
        return;
    }
    if (root_node->parent->left == root_node) {
        symb_node gap_node = *root_node;
        root_node->left = gap_node.parent;
        root_node->parent = gap_node.parent->parent;
        if (root_node->parent) root_node->parent->left = root_node;
        root_node->left->parent = root_node;
        root_node->left->left = gap_node.left;
    } else if (root_node->parent->right == root_node) {
        symb_node gap_node = *root_node;
        root_node->right = gap_node.parent;
        root_node->parent = gap_node.parent->parent;
        if (root_node->parent) root_node->parent->right = root_node;
        root_node->right->parent = root_node;
        root_node->right->right = gap_node.right;
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
    for (int i = 0; i < q_1_coeff; i++) {
        cin >> temp;
        make_rotate_coeff(vertexes_coeff[temp - 1]);
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
    for (int i = 0; i < q_2_symb; i++) {
        cin >> temp;
        make_rotate_symb(vertexes_symb[temp - 1]);
    }

}