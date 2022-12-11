#include <iostream>
using namespace std;

struct nodeTFC {
    string val;
    unsigned char height;
    int grade = 3;
    int count = 1;
    nodeTFC* left;
    nodeTFC* right;
    nodeTFC(string v) { val = v; left = right = nullptr; height = 1; }
};


struct listTFC {
    nodeTFC* root = nullptr;

    unsigned char height(nodeTFC* p) {
        return p ? p->height : 0;
    }

    int bFactor(nodeTFC* p) {
        return height(p->right) - height(p->left);
    }

    void fixHeight(nodeTFC* p) {
        unsigned char hl = height(p->left);
        unsigned char hr = height(p->right);
        p->height = (hl > hr ? hl : hr) + 1;
    }

    nodeTFC* rotateRight(nodeTFC* p) {
        nodeTFC* q = p->left;
        q->left = p->right;
        q->right = p;
        fixHeight(p);
        fixHeight(q);
        return q;
    }

    nodeTFC* rotateLeft(nodeTFC* q) {
        nodeTFC* p = q->right;
        q->right = p->left;
        p->left = q;
        fixHeight(q);
        fixHeight(p);
        return p;
    }

    nodeTFC* balance(nodeTFC* p) {
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

    nodeTFC* insert(nodeTFC* p, string k) {
        if (!p) return new nodeTFC(k);
        if (k < p->val) {
            p->left = insert(p->left, k);
        } else {
            p->right = insert(p->right, k);
        }
        return balance(p);
    }

    nodeTFC* exists(string val, nodeTFC* gap_root) {
        if (gap_root == nullptr || gap_root->val == val) {
            return gap_root;
        } else if (gap_root->val > val) {
            return exists(val, gap_root->left);
        } else {
            return exists(val, gap_root->right);
        }
    }

    nodeTFC* insertCheck (nodeTFC* q, string k) {
        nodeTFC* newNode = exists(k, root);
        if (newNode != nullptr) {
            if (newNode->count == 1) {
                newNode->count = 2;
                newNode->grade = 1;
            } else if (newNode->count == 2) {
                newNode->count = 3;
                newNode->grade = 0;
            }
            return root;
        } else {
            return insert(root, k);
        }
    }

    int summary(string mas[], int n) {
        int res = 0;
        nodeTFC* help_node;
        for (int i = 0; i < n; i++) {
            help_node = exists(mas[i], root);
            res += help_node->grade;
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    listTFC li;
    string mas_1[n];
    string mas_2[n];
    string mas_3[n];
    string temp;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            li.root = li.insertCheck(li.root, temp);
            if (i == 0) {
                mas_1[j] = temp;
            } else if (i == 1) {
                mas_2[j] = temp;
            } else {
                mas_3[j] = temp;
            }
        }
    }
    int fir = li.summary(mas_1, n);
    int sec = li.summary(mas_2, n);
    int thi = li.summary(mas_3, n);
    cout << fir << " " << sec << " " << thi;
    return 0;
}