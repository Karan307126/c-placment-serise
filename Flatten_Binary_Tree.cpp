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

void flattenTree(node *&root)
{
    node *curr = root, *pre;
    while (curr != NULL)
    {
        if (curr->left)
        {
            pre = curr->left;
            while (pre->right)
                pre = pre->right;
            pre->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

void display(node *root)
{
    if (root == NULL)
        return;
    node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->right;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *root = NULL;
    root = creatingTree(root);
    flattenTree(root);
    display(root);
    return 0;
}