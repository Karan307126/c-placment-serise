#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *creatingTree(node *root)
{
    int data;
    cout << "Enter data of node : " << endl;
    cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = creatingTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = creatingTree(root->right);
    return root;
}

void morrisTraversel(node *root)
{
    if (root == NULL)
        return;
    node *curr = root, *pre;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
                pre = pre->right;

            if (pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

int main()
{
    node *root = NULL;
    root = creatingTree(root);
    morrisTraversel(root);
    return 0;
}