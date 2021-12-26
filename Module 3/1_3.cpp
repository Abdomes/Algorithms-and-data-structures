#include<iostream>

using namespace std;

class BinTree
{
private:
    struct Node
    {
        int data;
        Node* left, * right, * parent;
        Node(int data) :data(data), left(nullptr), right(nullptr),parent(nullptr) {}
        Node() {}
    }*root = nullptr;

    void insert(Node*& root, int x)
    {
        if (root == nullptr)
        {
            root = new Node(x);
            root->parent = nullptr;
            return;
        }
        if (x == root->data)
        {
            return;
        }
	    else if (root->data > x)
        {
            if (root->left)
            {
                insert(root->left, x);
            }
            else
            {
                root->left = new Node(x);
                root->left->parent = root;
            }
        }
        else
        {
            if (root->right)
            {
                insert(root->right, x);
            }
            else
            {
                root->right = new Node(x);
                root->right->parent = root;
            }
        }
    }

    void Post_Order(Node* root)
    {
        while (root != nullptr)
        {
            if (root->left != nullptr)
            {
                root = root->left;
            }
            else if (root->right != nullptr)
            {
                root = root->right;
            }
            else
            {
                cout << root->data << " ";
                root = root->parent;
                if (root == nullptr)
                {
                    break;
                }
                else if (root->left)
                {
                    root->left = nullptr;
                }
                else if (root->right)
                {
                    root->right = nullptr;
                }
            }
        }
    }
public:
    void insert(int x)
    {
        insert(root, x);
    }

    void Post_Order()
	{
        Post_Order(root);
    }
};

int main()
{
	BinTree tree;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tree.insert(x);
    }
    tree.Post_Order();
}
