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

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        return;
    }

    temp->next = head;
    head = temp;
}

void insertAtLast(Node *&head, int data)
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
}

void insertAtPosition(Node *&head, int data, int pos)
{
    if (pos == 1)
    {
        insertAtHead(head, data);
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
    node->next = temp->next;
    temp->next = node;
}

void deleteNode(Node *&head, int pos)
{
    if (head == NULL)
    {
        cout << "Linkedlist is empty." << endl;
        return;
    }
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while (count < pos && curr != NULL)
        {
            prev = curr;
            curr = curr->next;
            ++count;
        }
        if (curr == NULL)
        {
            cout << "Invalid position." << endl;
            return;
        }
        prev->next = curr->next;
        delete curr;
    }
}

// Recursive approch....(also exist one itretive approch and same as recursive approch.)
Node *reverse_linkedlist(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *temp = reverse_linkedlist(head->next);
    head->next->next = head;
    head->next = NULL;

    return temp;
}

void find_mid(Node *head)
{
    Node *fast = head->next;
    Node *slow = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
    }
    cout << "The middel element of linkedlist is " << slow->data << endl;
}

int main()
{
    Node *head = NULL;
    insertAtPosition(head, 5, 1);
    insertAtLast(head, 30);
    insertAtLast(head, 20);
    insertAtLast(head, 10);
    print(head);
    head = reverse_linkedlist(head);
    print(head);
    find_mid(head);
    deleteNode(head, 2);
    print(head);
    find_mid(head);
    delete head;
    return 0;
}