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

Node *kReverse(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    // First k nodes are reverse by this code ....
    Node *prev = NULL;
    Node *curr = head;
    Node *temp = NULL;
    int count = 0;
    while (count < k && curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        count++;
    }
    // Recursive call....
    if (temp != NULL)
        head->next = kReverse(temp, k);

    return prev;
}

int main()
{
    Node *head = NULL;
    insertAtLast(head, 3);
    insertAtLast(head, 5);
    insertAtLast(head, 7);
    insertAtLast(head, 8);
    insertAtLast(head, 2);
    insertAtLast(head, 9);
    print(head);
    head = kReverse(head, 2);
    print(head);
    return 0;
}