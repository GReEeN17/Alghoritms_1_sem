#include <iostream>
using namespace std;

struct nodeOSA {
    int val;
    unsigned char height;
    nodeOSA* left = nullptr;
    nodeOSA* right = nullptr;
};

unsigned char heightOSA(nodeOSA* p)
{
    return p?p->height:0;
}

int bfactorOSA(nodeOSA* p)
{
    return heightOSA(p->right)-heightOSA(p->left);
}

void fixheightOSA(nodeOSA* p)
{
    unsigned char hl = heightOSA(p->left);
    unsigned char hr = heightOSA(p->right);
    p->height = (hl>hr?hl:hr)+1;
}

nodeOSA* rotaterightOSA(nodeOSA* p)
{
    nodeOSA* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheightOSA(p);
    fixheightOSA(q);
    return q;
}

nodeOSA* rotateleftOSA(nodeOSA* q)
{
    nodeOSA* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheightOSA(q);
    fixheightOSA(p);
    return p;
}

nodeOSA* balanceOSA(nodeOSA* p)
{
    fixheightOSA(p);
    if( bfactorOSA(p)==2 )
    {
        if( bfactorOSA(p->right) < 0 )
            p->right = rotaterightOSA(p->right);
        return rotateleftOSA(p);
    }
    if( bfactorOSA(p)==-2 )
    {
        if( bfactorOSA(p->left) > 0  )
            p->left = rotateleftOSA(p->left);
        return rotaterightOSA(p);
    }
    return p;
}

nodeOSA* insertOSA(nodeOSA* p, int k)
{
    if( !p ) {
        nodeOSA* gap_node = new nodeOSA;
        gap_node->val = k;
        gap_node->height = 1;
        return gap_node;
    }
    if( k<p->val)
        p->left = insertOSA(p->left,k);
    else
        p->right = insertOSA(p->right,k);
    return balanceOSA(p);
}

nodeOSA* exists(int val, nodeOSA* gap_root) {
    if (gap_root == nullptr || gap_root->val == val) {
        return gap_root;
    } else if (gap_root->val > val) {
        return exists(val, gap_root->left);
    } else {
        return exists(val, gap_root->right);
    }
}

nodeOSA* checkInsertTFC (nodeOSA* gap_root, int k) {
    nodeOSA* newNode = exists(k, gap_root);
    if (newNode != nullptr) {
        return gap_root;
    } else {
        return insertOSA(gap_root, k);
    }
}

nodeOSA* maxElem (nodeOSA* gap_root) {
    if (gap_root->right == nullptr) {
        return gap_root;
    } else {
        return maxElem(gap_root->right);
    }
}

nodeOSA* remove(nodeOSA* root, int k)
{
    if (root == nullptr) {
        return root;
    }
    if (k < root->val) {
        root->left = remove(root->left, k);
    } else if (k > root->val) {
        root->right = remove(root->right, k);
    } else if (root->left != nullptr && root->right != nullptr) {
        root->val = maxElem(root->left)->val;
        root->left = remove(root->left, root->val);
    } else {
        if (root->left != nullptr) {
            root = root->left;
        } else if (root->right != nullptr) {
            root = root->right;
        } else {
            root = nullptr;
        }
    }
    if (root == nullptr) {
        return root;
    }
    return balanceOSA(root);
}

int ordered_set_avl() {
    int n;
    cin >> n;
    if (n == 0) {
        return 0;
    }
    char func;
    int temp;
    nodeOSA* root = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> func;
        cin >> temp;
        if (func == 'A') {
            root = checkInsertTFC(root, temp);
            if (root != nullptr) {
                cout << bfactorOSA(root) << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (func == 'C') {
            nodeOSA* gapNode = exists(temp, root);
            if (root == nullptr) {

            }
            if (gapNode == nullptr) {
                cout << "N" << "\n";
            } else {
                cout << "Y" << "\n";
            }
        } else {
            root = remove(root, temp);
            if (root != nullptr) {
                cout << bfactorOSA(root) << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }
    return 0;
}