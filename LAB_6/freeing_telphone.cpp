#include <iostream>
using namespace std;

struct nodeFT {
    string val;
    unsigned char height;
    nodeFT* left;
    nodeFT* right;
    nodeFT(string v) { val = v; left = right = nullptr; height = 1; }
};


struct listFT {
    nodeFT* root = nullptr;
    int res = 0;

    unsigned char height(nodeFT* p) {
        return p ? p->height : 0;
    }

    int bFactor(nodeFT* p) {
        return height(p->right) - height(p->left);
    }

    void fixHeight(nodeFT* p) {
        unsigned char hl = height(p->left);
        unsigned char hr = height(p->right);
        p->height = (hl > hr ? hl : hr) + 1;
    }

    nodeFT* rotateRight(nodeFT* p) {
        nodeFT* q = p->left;
        q->left = p->right;
        q->right = p;
        fixHeight(p);
        fixHeight(q);
        return q;
    }

    nodeFT* rotateLeft(nodeFT* q) {
        nodeFT* p = q->right;
        q->right = p->left;
        p->left = q;
        fixHeight(q);
        fixHeight(p);
        return p;
    }

    nodeFT* balance(nodeFT* p) {
        fixHeight(p);
        if (bFactor(p) == 2) {
            if (bFactor(p->right) < 0) {
                p->right = rotateRight(p->right);
            }
            return rotateLeft(p);
        }
        if (bFactor(p) == -2) {
            if (bFactor(p->left) > 0) {
                p->left = rotateLeft(p->left);
            }
            return rotateRight(p);
        }
        return p;
    }

    nodeFT* insert(nodeFT* p, string k) {
        if (!p) return new nodeFT(k);
        if (k < p->val) {
            p->left = insert(p->left, k);
        } else {
            p->right = insert(p->right, k);
        }
        return balance(p);
    }

    nodeFT* exists(string val, nodeFT* gap_root) {
        if (gap_root == nullptr || gap_root->val == val) {
            return gap_root;
        } else if (gap_root->val > val) {
            return exists(val, gap_root->left);
        } else {
            return exists(val, gap_root->right);
        }
    }

    nodeFT* insertCheck (nodeFT* q, string k) {
        nodeFT* newNode = exists(k, root);
        if (newNode != nullptr) {
            int count = 0;
            bool flag;
            for (int i = 0; i < k.length(); i++) {
                flag = true;
                for (int j = i + 1; j < k.length(); j++) {
                    if (k[i] == k[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    count += 1;
                }
            }
            res += count;
            return root;
        } else {
            return insert(root, k);
        }
    }
};


int freeing_tele() {
    listFT li;
    int n;
    cin >> n;
    string temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        li.root = li.insertCheck(li.root, temp);
    }
    cout << li.res;
    return 0;
}