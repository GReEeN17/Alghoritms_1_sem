#include <iostream>
using namespace std;
int res = 0;

struct nodeFT {
    string val;
    unsigned char height;
    nodeFT* left = nullptr;
    nodeFT* right = nullptr;
};

unsigned char heightFT(nodeFT* p)
{
    return p?p->height:0;
}

int bfactorFT(nodeFT* p)
{
    return heightFT(p->right)-heightFT(p->left);
}

void fixheightFT(nodeFT* p)
{
    unsigned char hl = heightFT(p->left);
    unsigned char hr = heightFT(p->right);
    p->height = (hl>hr?hl:hr)+1;
}

nodeFT* rotaterightFT(nodeFT* p)
{
    nodeFT* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheightFT(p);
    fixheightFT(q);
    return q;
}

nodeFT* rotateleftFT(nodeFT* q)
{
    nodeFT* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheightFT(q);
    fixheightFT(p);
    return p;
}

nodeFT* balanceFT(nodeFT* p)
{
    fixheightFT(p);
    if( bfactorFT(p)==2 )
    {
        if( bfactorFT(p->right) < 0 )
            p->right = rotaterightFT(p->right);
        return rotateleftFT(p);
    }
    if( bfactorFT(p)==-2 )
    {
        if( bfactorFT(p->left) > 0  )
            p->left = rotateleftFT(p->left);
        return rotaterightFT(p);
    }
    return p;
}

nodeFT* insertFT(nodeFT* p, string k)
{
    if( !p ) {
        nodeFT* gap_node = new nodeFT;
        gap_node->val = k;
        gap_node->height = 1;
        return gap_node;
    }
    if( k<p->val)
        p->left = insertFT(p->left,k);
    else
        p->right = insertFT(p->right,k);
    return balanceFT(p);
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

nodeFT* checkInsertTFC (nodeFT* gap_root, string k) {
    nodeFT* newNode = exists(k, gap_root);
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
        return gap_root;
    } else {
        return insertFT(gap_root, k);
    }
}

int freeing_telephone() {
    int n;
    cin >> n;
    string temp;
    nodeFT* root = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        root = checkInsertTFC(root, temp);
    }
    cout << res;
    return 0;
}