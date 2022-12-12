#include <iostream>
using namespace std;

struct nodeMl {
    int val;
    unsigned char height;
    int l;
    int r;
    nodeMl* left = nullptr;
    nodeMl* right = nullptr;
};

unsigned char heightML(nodeMl* p)
{
    return p?p->height:0;
}

int bfactorML(nodeMl* p)
{
    return heightML(p->right)-heightML(p->left);
}

void fixheightML(nodeMl* p)
{
    unsigned char hl = heightML(p->left);
    unsigned char hr = heightML(p->right);
    p->height = (hl>hr?hl:hr)+1;
}

nodeMl* rotaterightML(nodeMl* p)
{
    nodeMl* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheightML(p);
    fixheightML(q);
    return q;
}

nodeMl* rotateleftML(nodeMl* q)
{
    nodeMl* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheightML(q);
    fixheightML(p);
    return p;
}

nodeMl* balanceML(nodeMl* p)
{
    if( bfactorML(p->right) < 0 )
        p->right = rotaterightML(p->right);
    return rotateleftML(p);
}



int preOrderTraversalSetML (nodeMl* gap_root, int k) {
    if (gap_root != nullptr) {
        if (gap_root->left != nullptr) {
            gap_root->l = k++;
        } else {
            gap_root->l = 0;
        }
        k = preOrderTraversalSetML(gap_root->left, k);
        if (gap_root->right != nullptr) {
            gap_root->r = k++;
        } else {
            gap_root->r = 0;
        }
        k = preOrderTraversalSetML(gap_root->right, k);
    }
    return k;
}

void preOrderTraversalML (nodeMl* gap_root) {
    if (gap_root != nullptr) {
        cout << gap_root->val << " " << gap_root->l << " " << gap_root->r << "\n";
        preOrderTraversalML(gap_root->left);
        preOrderTraversalML(gap_root->right);
    }
}


int left_rotation() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    nodeMl* mas[n];
    int left, right;
    for (int i = 0; i < n; i++) {
        mas[i] = new nodeMl;
    }
    for (int i = 0; i < n; i++) {
        cin >> mas[i]->val;
        cin >> left >> right;
        if (left != 0) {
            mas[i]->left = mas[left - 1];
        }
        if (right != 0) {
            mas[i]->right = mas[right - 1];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (mas[i]->left == nullptr && mas[i]->right == nullptr) {
            mas[i]->height = 1;
        } else if (mas[i]->left != nullptr && mas[i]->right != nullptr) {
            mas[i]->height = 1 + max(mas[i]->left->height, mas[i]->right->height);
        } else if (mas[i]->left == nullptr) {
            mas[i]->height = 1 + mas[i]->right->height;
        } else {
            mas[i]->height = 1 + mas[i]->left->height;
        }
    }
    cout << n << "\n";
    nodeMl* root = balanceML(mas[0]);
    preOrderTraversalSetML(root, 2);
    preOrderTraversalML(root);
    return 0;
}