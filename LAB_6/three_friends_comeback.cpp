#include <iostream>
using namespace std;

struct nodeTFC {
    string val;
    int grade;
    int count;
    unsigned char height;
    nodeTFC* left = nullptr;
    nodeTFC* right = nullptr;
};

unsigned char heightTFC(nodeTFC* p)
{
    return p?p->height:0;
}

int bfactorTFC(nodeTFC* p)
{
    return heightTFC(p->right)-heightTFC(p->left);
}

void fixheightTFC(nodeTFC* p)
{
    unsigned char hl = heightTFC(p->left);
    unsigned char hr = heightTFC(p->right);
    p->height = (hl>hr?hl:hr)+1;
}

nodeTFC* rotaterightTFC(nodeTFC* p)
{
    nodeTFC* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheightTFC(p);
    fixheightTFC(q);
    return q;
}

nodeTFC* rotateleftTFC(nodeTFC* q)
{
    nodeTFC* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheightTFC(q);
    fixheightTFC(p);
    return p;
}

nodeTFC* balanceTFC(nodeTFC* p)
{
    fixheightTFC(p);
    if( bfactorTFC(p)==2 )
    {
        if( bfactorTFC(p->right) < 0 )
            p->right = rotaterightTFC(p->right);
        return rotateleftTFC(p);
    }
    if( bfactorTFC(p)==-2 )
    {
        if( bfactorTFC(p->left) > 0  )
            p->left = rotateleftTFC(p->left);
        return rotaterightTFC(p);
    }
    return p;
}

nodeTFC* insertTFC(nodeTFC* p, string k)
{
    if( !p ) {
        nodeTFC* gap_node = new nodeTFC;
        gap_node->val = k;
        gap_node->height = 1;
        gap_node->count = 1;
        gap_node->grade = 3;
        return gap_node;
    }
    if( k<p->val)
        p->left = insertTFC(p->left,k);
    else
        p->right = insertTFC(p->right,k);
    return balanceTFC(p);
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

nodeTFC* checkInsertTFC (nodeTFC* gap_root, string k) {
    nodeTFC* newNode = exists(k, gap_root);
    if (newNode != nullptr) {
        if (newNode->count == 1) {
            newNode->count++;
            newNode->grade = 1;
        } else if (newNode->count == 2) {
            newNode->count++;
            newNode->grade = 0;
        }
        return gap_root;
    } else {
        return insertTFC(gap_root, k);
    }
}

int summary(string mas[], int n, nodeTFC* root) {
    int res = 0;
    nodeTFC* help_node;
    for (int i = 0; i < n; i++) {
        help_node = exists(mas[i], root);
        res += help_node->grade;
    }
    return res;
}

int three_friends_comeback() {
    int n;
    cin >> n;
    string fir_mas[n];
    string sec_mas[n];
    string thi_mas[n];
    string temp;
    nodeTFC* root = nullptr;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            root = checkInsertTFC(root, temp);
            if (i == 0) {
                fir_mas[j] = temp;
            } else if (i == 1) {
                sec_mas[j] = temp;
            } else {
                thi_mas[j] = temp;
            }
        }
    }
    int sum_fir = summary(fir_mas, n, root);
    int sum_sec = summary(sec_mas, n, root);
    int sum_thi = summary(thi_mas, n, root);
    cout << sum_fir << " " << sum_sec << " " << sum_thi;
    return 0;
}