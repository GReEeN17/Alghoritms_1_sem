#include <iostream>
using namespace std;

struct FriendNode{
    string val;
    int grade = 0;
    int count = 0;
    FriendNode* left = nullptr;
    FriendNode* right = nullptr;
    FriendNode* parent = nullptr;
};

struct FriendBST {
    FriendNode* root = nullptr;

    FriendNode* exists(string val, FriendNode* gap_root) {
        if (gap_root == nullptr || gap_root->val == val) {
            return gap_root;
        } else if (gap_root->val > val) {
            return exists(val, gap_root->left);
        } else {
            return exists(val, gap_root->right);
        }
    }

    void insert(string val) {
        FriendNode* newNode = exists(val, root);
        if (newNode != nullptr) {
            if (newNode->count == 1) {
                newNode->count = 2;
                newNode->grade = 1;
            } else if (newNode->count == 2) {
                newNode->count = 3;
                newNode->grade = 0;
            }
            return;
        }
        newNode = new FriendNode;
        newNode->val = val;
        newNode->count = 1;
        newNode->grade = 3;
        if (root == nullptr) {
            root = newNode;
            return;
        } else {
            FriendNode* x = root;
            while (x != nullptr) {
                if (newNode->val > x->val) {
                    if (x->right != nullptr) {
                        x = x->right;
                    } else {
                        x->right = newNode;
                        newNode->parent = x;
                        break;
                    }
                } else if (newNode->val < x->val){
                    if (x->left != nullptr) {
                        x = x->left;
                    } else {
                        x->left = newNode;
                        newNode->parent = x;
                        break;
                    }
                }
            }
        }
    }

    int summary(string mas[], int n) {
        int res = 0;
        FriendNode* help_node;
        for (int i = 0; i < n; i++) {
            help_node = exists(mas[i], root);
            res += help_node->grade;
        }
        return res;
    }
};

int three_friends() {
    FriendBST fr;
    int n;
    cin >> n;
    string fir_mas[n];
    string sec_mas[n];
    string thi_mas[n];
    string temp;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            fr.insert(temp);
            if (i == 0) {
                fir_mas[j] = temp;
            } else if (i == 1) {
                sec_mas[j] = temp;
            } else {
                thi_mas[j] = temp;
            }
        }
    }
    int fir = fr.summary(fir_mas, n);
    int sec = fr.summary(sec_mas, n);
    int thi = fr.summary(thi_mas, n);
    cout << fir << " " << sec << " " << thi;
    return 0;
}