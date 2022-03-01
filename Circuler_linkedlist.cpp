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

// Here, new node is insert after the given element....
void insertion(Node *&tail, int data, int element)
{
    Node *node = new Node(data);
    if (tail == NULL)
    {
        tail = node;
        tail->next = node;
        return;
    }
    Node *temp = tail->next;
    while (temp->data != element && temp != tail)
    {
        temp = temp->next;
    }
    if (temp == tail && temp->data != element)
    {
        cout << "Invalid element you have enter." << endl;
        return;
    }
    else if (tail->data == element)
    {
        node->next = tail->next;
        tail->next = node;
        tail = node;
    }
    else
    {
        node->next = temp->next;
        temp->next = node;
    }
}

bool isCircular(Node *head)
{
    if (head == NULL)
    {
        return true;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast != slow)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast == NULL)
        return false;
    else
        return true;
}

void printCLL(Node *&tail)
{
    Node *temp = tail->next;
    while (temp != tail)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data << " -> ";
}

int main()
{
    Node *tail = NULL;
    insertion(tail, 5, 0);
    insertion(tail, 7, 5);
    insertion(tail, 6, 5);
    insertion(tail, 8, 7);
    printCLL(tail);
    if (isCircular(tail))
        cout << "List is circuler." << endl;
    else
        cout << "List is not circuler." << endl;
    delete tail;
    return 0;
}