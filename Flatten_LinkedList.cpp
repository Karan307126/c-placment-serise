#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    Node *ans = new Node(-1);
    Node *temp = ans;
    while (left != NULL and right != NULL)
    {
        if (left->data < right->data)
        {
            temp->child = left;
            temp = left;
            left = left->child;
        }
        else
        {
            temp->child = right;
            temp = right;
            right = right->child;
        }
    }
    while (left != NULL)
    {
        temp->child = left;
        temp = left;
        left = left->child;
    }
    while (right != NULL)
    {
        temp->child = right;
        temp = right;
        right = right->child;
    }
    ans = ans->child;
    return ans;
}

Node *flattenLinkedList(Node *head)
{
    if (head == NULL)
        return head;
    Node *down = head;
    Node *right = head->next;
    down->next = NULL;
    right = flattenLinkedList(right);

    Node *ans = merge(down, right);

    return ans;
}

void display(Node *head)
{
    if (head != NULL)
    {
        Node *temp1 = head;
        while (temp1 != NULL)
        {
            Node *temp2 = temp1;
            while (temp2 != NULL)
            {
                cout << temp2->data << " -> ";
                temp2 = temp2->child;
            }
            cout << "NULL" << endl;
            temp1 = temp1->next;
        }
        cout << endl;
    }
}

int main()
{
    Node *head = new Node(1);
    Node *node1 = new Node(14);
    Node *node2 = new Node(19);
    Node *node3 = new Node(3);
    Node *node4 = new Node(9);
    Node *node5 = new Node(10);
    Node *node6 = new Node(20);

    head->next = node1;
    node1->next = node2;
    head->child = node3;
    node3->child = node4;
    node4->child = node5;
    node2->child = node6;

    display(head);
    head = flattenLinkedList(head);
    cout << "Ans = ";
    display(head);

    delete (head);
    delete (node1);
    delete (node2);
    delete (node3);
    delete (node4);
    delete (node5);
    delete (node6);
    return 0;
}