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

void insertion(Node *&head, int data)
{
    Node *new_node = new Node(data);
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void display(Node *&head)
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

Node *reverse_Kgroup(Node *head, int k)
{
    if (head == NULL)
        return NULL;

    Node *prev = NULL;
    Node *curr = head;
    Node *temp = NULL;
    int count = 0;
    while (count < k and curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        count++;
    }
    if (temp != NULL)
    {
        head->next = reverse_Kgroup(temp, k);
    }
    return prev;
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

int main()
{
    Node *head = NULL;
    insertion(head, 54);
    insertion(head, 68);
    insertion(head, 32);
    insertion(head, 91);
    insertion(head, 48);
    display(head);
    head = reverse_Kgroup(head, 2);
    display(head);

    if (isCircular(head))
        cout << "List is circuler." << endl;
    else
        cout << "List is not circuler." << endl;
    return 0;
}