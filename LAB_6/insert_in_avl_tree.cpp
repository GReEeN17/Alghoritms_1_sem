#include <iostream>
using namespace std;

struct nodeIT {
    int val;
    unsigned char height;
    int l;
    int r;
    nodeIT* left;
    nodeIT* right;
};

unsigned char heightIT(nodeIT* p)
{
    return p?p->height:0;
}

int bfactorIT(nodeIT* p)
{
    return heightIT(p->right)-heightIT(p->left);
}

void fixheightIT(nodeIT* p)
{
    unsigned char hl = heightIT(p->left);
    unsigned char hr = heightIT(p->right);
    p->height = (hl>hr?hl:hr)+1;
}

nodeIT* rotaterightIT(nodeIT* p)
{
    nodeIT* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheightIT(p);
    fixheightIT(q);
    return q;
}

nodeIT* rotateleftIT(nodeIT* q)
{
    nodeIT* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheightIT(q);
    fixheightIT(p);
    return p;
}

nodeIT* balance(nodeIT* p)
{
    fixheightIT(p);
    if( bfactorIT(p)==2 )
    {
        if( bfactorIT(p->right) < 0 )
            p->right = rotaterightIT(p->right);
        return rotateleftIT(p);
    }
    if( bfactorIT(p)==-2 )
    {
        if( bfactorIT(p->left) > 0  )
            p->left = rotateleftIT(p->left);
        return rotaterightIT(p);
    }
    return p;
}

nodeIT* insert(nodeIT* p, int k)
{
    if( !p ) {
        nodeIT* gap_node = new nodeIT;
        gap_node->val = k;
        gap_node->height = 1;
        return gap_node;
    }
    if( k<p->val)
        p->left = insert(p->left,k);
    else
        p->right = insert(p->right,k);
    return balance(p);
}

int preOrderTraversalSetIT (nodeIT* gap_root, int k) {
    if (gap_root != nullptr) {
        if (gap_root->left != nullptr) {
            gap_root->l = k++;
        } else {
            gap_root->l = 0;
        }
        k = preOrderTraversalSetIT(gap_root->left, k);
        if (gap_root->right != nullptr) {
            gap_root->r = k++;
        } else {
            gap_root->r = 0;
        }
        k = preOrderTraversalSetIT(gap_root->right, k);
    }
    return k;
}

void preOrderTraversalIT (nodeIT* gap_root) {
    if (gap_root != nullptr) {
        cout << gap_root->val << " " << gap_root->l << " " << gap_root->r << "\n";
        preOrderTraversalIT(gap_root->left);
        preOrderTraversalIT(gap_root->right);
    }
}


int insert_in_avl() {
    int n;
    cin >> n;
    if (n == 0) {
        int temp;
        cin >> temp;
        cout << 1 << "\n";
        cout << temp << " " << 0 << " " << 0 << "\n";
        return 0;
    }
    nodeIT* mas[n];
    for (int i = 0; i < n; i++) {
        mas[i] = new nodeIT;
    }
    int left, right;
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
    int new_elem;
    cin >> new_elem;
    cout << n + 1 << "\n";
    nodeIT* root = insert(mas[0], new_elem);
    preOrderTraversalSetIT(root, 2);
    preOrderTraversalIT(root);
    return 0;
}