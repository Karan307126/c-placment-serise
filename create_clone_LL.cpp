#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

void insert(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
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

Node *copyList(Node *head)
{
    // step 1 : create clone list with next links
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;
    Node *temp = head;
    while (temp != NULL)
    {
        insert(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // step 2 : change links between clone and original
    Node *original = head;
    Node *clone = cloneHead;
    while (original != NULL and clone != NULL)
    {
        Node *next = original->next;
        original->next = clone;
        original = next;

        next = clone->next;
        clone->next = original;
        clone = next;
    }

    // step 3 : random links copy
    temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL)
            temp->next->random = temp->random ? temp->random->next : temp->random;

        temp = temp->next->next;
    }

    // step 4 : reverse changes in step 2
    original = head;
    clone = cloneHead;
    while (clone != NULL and original != NULL)
    {
        original->next = original->next ? original->next->next : original->next;
        clone->next = clone->next ? clone->next->next : clone->next;

        original = original->next;
        clone = clone->next;
    }

    // step 5 : return cloneHead.
    return cloneHead;
}

void display(Node *head)
{
    if (head != NULL)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

void displayRandom(Node *head)
{
    while (head != NULL)
    {
        cout << " head data : " << head->data << " ";
        if (head->random != NULL)
        {
            cout << " head random data : " << head->random->data;
        }
        else
        {
            cout << " head random data : NULL";
        }
        head = head->next;
        cout << endl;
    }
}

int main()
{
    Node *head = new Node(1);
    Node *node1 = new Node(2);
    Node *node2 = new Node(3);
    Node *node3 = new Node(4);
    Node *node4 = new Node(5);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    head->random = node2;
    node1->random = head;
    node2->random = node4;
    node3->random = node2;
    node4->random = node1;

    display(head);
    displayRandom(head);
    cout << endl
         << endl;
    Node *clone = copyList(head);
    display(clone);
    displayRandom(clone);

    delete (head);
    delete (node1);
    delete (node2);
    delete (node3);
    delete (node4);
    return 0;
}