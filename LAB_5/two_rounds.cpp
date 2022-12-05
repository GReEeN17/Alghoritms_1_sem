#include <iostream>
using namespace std;

struct RoundNode {
    int val;
    RoundNode* parent = nullptr;
    RoundNode* left = nullptr;
    RoundNode* right = nullptr;
};

struct roundBST {
    RoundNode* root = new RoundNode;

    RoundNode* maximum(RoundNode* x, int val) {
        RoundNode* successor = nullptr;
        while (x != nullptr && x->val < val) {
            if (successor == nullptr || successor->val < x->val) {
                successor = x;
            }
            x = x->parent;
        }
        if (successor == nullptr) {
            return x;
        } else {
            return successor;
        }
    }

    void makeBST(int mas[], int n) {
        root->val = mas[0];
        RoundNode* current = root;
        RoundNode* gap_node;
        for (int i = 1; i < n; i++) {
            RoundNode* newNode = new RoundNode;
            newNode->val = mas[i];
            if (mas[i] < mas[i - 1]) {
                current->left = newNode;
                newNode->parent = current;
                current = newNode;
            } else {
                gap_node = maximum(current, mas[i]);
                gap_node->right = newNode;
                newNode->parent = gap_node;
                current = newNode;
            }
        }
    }

    void postorderTraversal (RoundNode* gap_node) {
        if (gap_node != nullptr) {
            postorderTraversal(gap_node->left);
            postorderTraversal(gap_node->right);
            cout << gap_node->val << " ";
        }
    }
};

int two_rounds() {
    roundBST ro;
    int n;
    cin >> n;
    int mas[n];
    if (n == 0) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    ro.makeBST(mas, n);
    ro.postorderTraversal(ro.root);
    return 0;
}
