#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insert(Node *&tail, Node *temp)
{
    tail->next = temp;
    tail = temp;
}

Node *sortLL(Node *head)
{
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            insert(zeroTail, temp);
        else if (temp->data == 1)
            insert(oneTail, temp);
        else
            insert(twoTail, temp);

        temp = temp->next;
    }

    if (oneHead->next != NULL)
        zeroTail->next = oneHead->next;
    else
        zeroTail->next = twoHead->next;

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;

    delete (oneHead);
    delete (twoHead);
    delete (zeroHead);

    return head;
}

void display(Node *head)
{
    if (head == NULL)
        return;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = new Node(1);
    Node *node1 = new Node(2);
    Node *node2 = new Node(2);
    Node *node3 = new Node(0);
    Node *node4 = new Node(1);
    Node *node5 = new Node(2);
    Node *node6 = new Node(0);
    Node *node7 = new Node(0);
    Node *node8 = new Node(2);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = NULL;

    display(head);
    head = sortLL(head);
    display(head);

    delete (head);
    delete (node1);
    delete (node2);
    delete (node3);
    delete (node4);
    delete (node5);
    delete (node6);
    delete (node7);
    delete (node8);
    return 0;
}