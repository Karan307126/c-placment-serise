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

Node *getMid(Node *head)
{
    Node *slow = head, *fast = head->next;
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *reverseLL(Node *temp)
{
    Node *curr = temp;
    Node *prev = NULL, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrom(Node *head)
{
    if (head->next == NULL)
        return true;

    Node *mid = getMid(head);
    mid->next = reverseLL(mid->next);
    Node *head1 = head, *head2 = mid->next;
    while (head2 != NULL)
    {
        if (head1->data != head2->data)
            return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    mid->next = reverseLL(mid->next);
    return true;
}

int main()
{
    Node *head = new Node(1);
    Node *node1 = new Node(2);
    Node *node2 = new Node(3);
    Node *node3 = new Node(3);
    Node *node4 = new Node(2);
    Node *node5 = new Node(1);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    if (isPalindrom(head))
        cout << "Linked list is palindrom." << endl;
    else
        cout << "Linked list is not palindrom." << endl;

    delete (head);
    delete (node1);
    delete (node2);
    delete (node3);
    delete (node4);
    return 0;
}