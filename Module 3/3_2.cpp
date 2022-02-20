#include<iostream>

using namespace std;

struct Node 
{
    int key;
    unsigned char height;
    int size;
    Node* left;
    Node* right;
    Node(int key) : key(key), left(nullptr), right(nullptr), height(1),size(1) {}
};

unsigned char height(Node* root)
{
    return root ? root->height:0;
}

int GetSize(Node* CurRoot)
{
    return CurRoot ? CurRoot->size : 0;
}

int bfactor(Node* root)
{
    return height(root->right) - height(root->left);
}

void fixheight(Node* root)
{
    unsigned char hl = height(root->left);
    unsigned char hr = height(root->right);
    root->height = (hl > hr ? hl + 1 : hr + 1);
    root->size = GetSize(root->left) + 1 + GetSize(root->right);
}

Node* rotateright(Node* root) 
{
    Node* q = root->left;
    root->left = q->right;
    q->right = root;
    fixheight(root);
    fixheight(q);
    return q;
}

Node* rotateleft(Node* root)
{
    Node* p = root->right;
    root->right = p->left;
    p->left = root;
    fixheight(root);
    fixheight(p);
    return p;
}

Node* balance(Node* root)
{
    fixheight(root);
    if (bfactor(root) == 2)
    {
        if (bfactor(root->right) < 0)
            root->right = rotateright(root->right);
        return rotateleft(root);
    }
    if (bfactor(root) == -2)
    {
        if (bfactor(root->left) > 0)
            root->left = rotateleft(root->left);
        return rotateright(root);
    }
    return root;
}

Node* insert(Node* root, int k)
{
    if (!root) return new Node(k);
    if (k < root->key)
        root->left = insert(root->left, k);
    else
        root->right = insert(root->right, k);
    return balance(root);
}

Node* findmin(Node* root) 
{
    return root->left ? findmin(root->left) : root;
}

Node* removemin(Node* root)
{
    if (root->left == nullptr)
        return root->right;
    root->left = removemin(root->left);
    return balance(root);
}

Node* remove(Node* root, int k)
{
    if (!root) return 0;
    if (k < root->key)
        root->left = remove(root->left, k);
    else if (k > root->key)
        root->right = remove(root->right, k);
    else 
    {
        Node* q = root->left;
        Node* r = root->right;
        delete root;
        if (!r) return q;
        Node* min = findmin(r);
        min->right = removemin(r);
        min->left = q;
        return balance(min);
    }
    return balance(root);
}

int GetHeight(Node* root)
{
    return root ? root->height : 0;
}

int keyByIndex(Node* CurRoot, int index)
{
    int leftsize = GetSize(CurRoot->left);
    if (index == leftsize)
    {
        return CurRoot->key;
    }
    if (index < leftsize)
    {
        return keyByIndex(CurRoot->left, index);
    }
    else
    {
        return keyByIndex(CurRoot->right, index - leftsize - 1);
    }
}

Node* root;

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        int a, k;
        cin >> a >> k;
        if (a > 0)root = insert(root, a);
        else root = remove(root, abs(a));
        arr[i] = keyByIndex(root, k);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
