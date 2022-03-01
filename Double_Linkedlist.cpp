#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertionAtHead(Node *&head, int data)
{
    Node *node = new Node(data);
    if (head == NULL)
    {
        head = node;
        return;
    }
    node->next = head;
    head->prev = node;
    head = node;
}

void insertionAtTail(Node *&head, int data)
{
    Node *node = new Node(data);
    if (head == NULL)
    {
        head = node;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = node;
    node->prev = temp;
}

void insertionAtpos(Node *&head, int data, int pos)
{
    if (pos == 1)
    {
        insertionAtHead(head, data);
        return;
    }
    Node *node = new Node(data);
    Node *temp = head;
    int count = 1;
    while (count < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        ++count;
    }
    if (temp == NULL)
    {
        cout << "Invalid position." << endl;
        return;
    }
    node->prev = temp;
    node->next = temp->next;
    temp->next->prev = node;
    temp->next = node;
}

void deletion(Node *&head, int pos)
{
    if (head == NULL)
    {
        cout << "Linked list is empty." << endl;
        return;
    }
    else if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
    else
    {
        Node *temp = head;
        int count = 1;
        while (count < pos && temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        if (temp == NULL)
        {
            cout << "Invalid position." << endl;
            return;
        }
        else if (temp->next == NULL)
        {
            temp->prev->next = NULL;
            delete temp;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }
}

void print(Node *&head)
{
    Node *temp = head;
    cout << "NULL <=> ";
    while (temp != NULL)
    {
        cout << temp->data << " <=> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = NULL;
    insertionAtTail(head, 45);
    insertionAtHead(head, 35);
    insertionAtHead(head, 25);
    insertionAtpos(head, 15, 2);
    print(head);
    deletion(head, 1);
    print(head);
    delete head;
    return 0;
}