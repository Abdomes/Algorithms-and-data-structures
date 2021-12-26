#include<iostream>

#include<queue>

using namespace std;

class BinHeap
{
private:
    struct Node
    {
        Node* left, * right;
        int key, prior;
        Node(int key, int prior) :key(key), prior(prior), left(nullptr), right(nullptr) {}
        Node(int key) :key(key), left(nullptr), right(nullptr) {}
    } *root = nullptr, * BinRoot = nullptr;

    void split(Node* CurRoot, int key, Node*& a, Node*& b)
    {
        if (CurRoot == nullptr)
        {
            a = b = nullptr;
        }
        else if (CurRoot->key < key)
        {
            split(CurRoot->right, key, CurRoot->right, b);
            a = CurRoot;
        }
        else
        {
            split(CurRoot->left, key, a, CurRoot->left);
            b = CurRoot;
        }
    }

    void InsertTreap(int key, int prior, Node*& root)
    {
        if (root == nullptr)
        {
            root = new Node(key, prior);
            return;
        }
        else if (root->prior >= prior)
        {
            if (root->key > key)
            {
                InsertTreap(key, prior, root->left);
            }
            else
            {
                InsertTreap(key, prior, root->right);
            }
        }
        else
        {
            Node* less = nullptr, * unless = nullptr;
            split(root, key, less, unless);
            Node* node = new Node(key, prior);
            node->left = less;
            node->right = unless;
            root = node;
        }
    }

    void InsertBinTree(int key, Node*& root)
    {
        if (root == nullptr)
        {
            root = new Node(key);
            return;
        }
        if (root->key > key)
        {
            InsertBinTree(key, root->left);
        }
        else
        {
            InsertBinTree(key, root->right);
        }
    }

    int MaxWidth(Node* root)
    {
        if (root == nullptr) { return 0; }
        int maxx = 0;
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int c = q.size();
            maxx = max(c, maxx);
            while (c--)
            {
                Node* node = q.front();
                q.pop();
                if (node->left != nullptr)
                    q.push(node->left);
                if (node->right != nullptr)
                    q.push(node->right);
            }
        }
        return maxx;
    }
public:

    void InsertTreap(int key, int prior)
    {
        InsertTreap(key, prior, root);
    }

    void InsertBinTree(int key)
    {
        InsertBinTree(key, BinRoot);
    }

    int MaxWidthBinTree()
    {
        return MaxWidth(BinRoot);
    }

    int MaxWidthTreap()
    {
        return MaxWidth(root);
    }
};

int main()
{
    BinHeap binheap;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        binheap.InsertTreap(x, y);
        binheap.InsertBinTree(x);
    }
    int first = binheap.MaxWidthBinTree();
    int second = binheap.MaxWidthTreap();
    cout << second - first;
}
