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

Node *reverse(Node *temp)
{
    Node *curr = temp;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void insert(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val);
    if (head == NULL and tail == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

Node *add(Node *first, Node *second)
{
    int carry = 0;
    Node *ansHead = NULL;
    Node *ansTail = NULL;

    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0;
        if (first != NULL)
            val1 = first->data;

        int val2 = 0;
        if (second != NULL)
            val2 = second->data;

        int sum = val1 + val2 + carry;
        int digit = sum % 10;
        insert(ansHead, ansTail, digit);

        carry = sum / 10;

        if (first != NULL)
            first = first->next;
        if (second != NULL)
            second = second->next;
    }
    return ansHead;
}

void display(Node *node)
{
    if (node != NULL)
    {
        Node *temp = node;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

Node *addNumber(Node *first, Node *second)
{
    first = reverse(first);
    second = reverse(second);

    Node *ans = add(first, second);

    ans = reverse(ans);
    return ans;
}

int main()
{
    Node *first = new Node(3);
    Node *node1 = new Node(4);
    Node *node2 = new Node(5);

    Node *second = new Node(4);
    Node *node3 = new Node(5);

    first->next = node1;
    node1->next = node2;
    second->next = node3;
    cout << "First linked list = ";
    display(first);
    cout << "Second linked list = ";
    display(second);
    Node *ans = addNumber(first, second);
    cout << "Answer linked list = ";
    display(ans);

    delete (first);
    delete (second);
    delete (node1);
    delete (node2);
    delete (node3);
    return 0;
}