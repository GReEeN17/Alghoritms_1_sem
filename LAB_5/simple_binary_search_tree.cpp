#include <iostream>
#include <sstream>
using namespace std;

struct Node {
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
};

struct binarySearchTree {
    Node* root = nullptr;

    Node* exists(int val, Node* gap_root) {
        if (gap_root == nullptr || gap_root->val == val) {
            return gap_root;
        } else if (gap_root->val > val) {
            return exists(val, gap_root->left);
        } else {
            return exists(val, gap_root->right);
        }
    }

    Node* next(int val) {
        Node* current = root;
        Node* successor = nullptr;
        while (current != nullptr) {
            if (current->val > val) {
                successor = current;
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return successor;
    }

    Node* prev(int val) {
        Node* current = root;
        Node* successor = nullptr;
        while (current != nullptr) {
            if (current->val < val) {
                successor = current;
                current = current->right;
            } else {
                current = current->left;
            }
        }
        return successor;
    }

    void insert(int val) {
        if (exists(val, root) != nullptr) {
            return;
        }
        Node* newNode = new Node;
        newNode->val = val;
        if (root == nullptr) {
            root = newNode;
            return;
        } else {
            Node* x = root;
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

    void delete_bin_tree(int val) {
        Node* newNode = exists(val, root);
        if (newNode == nullptr) {
            return;
        }
        if (newNode == root) {
            if (newNode->left == nullptr && newNode->right == nullptr) {
                root = nullptr;
            } else if (newNode->left != nullptr && newNode->right != nullptr) {
                newNode = newNode->right;
                while (newNode->left != nullptr) {
                    newNode = newNode->left;
                }
                if (newNode->parent == root) {
                    newNode->parent = nullptr;
                    newNode->left = root->left;
                    root = newNode;
                } else {
                    if (newNode->right != nullptr) {
                        newNode->parent->left = newNode->right;
                        root->val = newNode->val;
                    } else {
                        newNode->parent->left = nullptr;
                        root->val = newNode->val;
                    }
                }
            } else {
                if (newNode->left != nullptr) {
                    newNode->left->parent = nullptr;
                    root = newNode->left;
                } else {
                    newNode = newNode->right;
                    while (newNode->left != nullptr) {
                        newNode = newNode->left;
                    }
                    if (newNode->parent == root) {
                        newNode->parent = nullptr;
                        root = newNode;
                    } else {
                        if (newNode->right != nullptr) {
                            newNode->parent->left = newNode->right;
                            root->val = newNode->val;
                        }
                    }
                }
            }
        } else {
            Node *p = newNode->parent;
            if (newNode->left == nullptr && newNode->right == nullptr) {
                if (p->left == newNode) {
                    p->left = nullptr;
                    return;
                } else {
                    p->right = nullptr;
                    return;
                }
            } else if (newNode->left == nullptr || newNode->right == nullptr) {
                if (newNode->left == nullptr) {
                    if (p->left == newNode) {
                        p->left = newNode->right;
                    } else {
                        p->right = newNode->right;
                    }
                    newNode->right->parent = p;
                } else {
                    if (p->left == newNode) {
                        p->left = newNode->left;
                    } else {
                        p->right = newNode->left;
                    }
                    newNode->left->parent = p;
                }
            } else {
                Node* successor = newNode;
                successor = successor->right;
                while (successor->left != nullptr) {
                    successor = successor->left;
                }
                newNode->val = successor->val;
                if (successor->parent->left == successor) {
                    successor->parent->left = successor->right;
                    if (successor->right != nullptr) {
                        successor->right->parent = successor->parent;
                    }
                } else {
                    successor->parent->right = successor->right;
                    if (successor->right != nullptr) {
                        successor->right->parent = successor->parent;
                    }
                }
            }
        }
    }
};

int simple_binary_search_tree() {
    binarySearchTree bi;
    string s;
    string func;
    int val;
    Node* res;
    while(getline(cin, s)) {
        if (s.empty()) {
            break;
        }
        istringstream iss(s);
        iss >> func;
        iss >> val;
        if (func == "insert"){
            bi.insert(val);
        } else if (func == "delete") {
            bi.delete_bin_tree(val);
        } else if (func == "exists") {
            res = bi.exists(val, bi.root);
            if (res == nullptr) {
                cout << "false" << "\n";
            } else {
                cout << "true" << "\n";
            }
        } else if (func == "next") {
            res = bi.next(val);
            if (res == nullptr) {
                cout << "none" << "\n";
            } else {
                cout << res->val << "\n";
            }
        } else {
            res = bi.prev(val);
            if (res == nullptr) {
                cout << "none" << "\n";
            } else {
                cout << res->val << "\n";
            }
        }
    }
    return 0;
}
