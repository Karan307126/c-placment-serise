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

void RemoveDuplicate(Node *head)
{
    if (head == NULL)
        return;
    Node *curr = head;
    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = temp->next;
            delete (temp);
        }
        else
            curr = curr->next;
    }
}

void display(Node *head)
{
    if (head == NULL)
    {
        cout << "Linked list is empty." << endl;
        return;
    }
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
    Node *head = new Node(2);
    Node *node1 = new Node(2);
    Node *node2 = new Node(4);
    Node *node3 = new Node(5);
    Node *node4 = new Node(5);
    Node *node5 = new Node(6);
    Node *node6 = new Node(6);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    display(head);

    RemoveDuplicate(head);

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