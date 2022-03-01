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

Node *FloydLoopDetection(Node *head)
{
    if (head == NULL)
        return NULL;
    else if (head->next == NULL)
        return NULL;

    Node *slow = head, *fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;

        if (slow == fast)
            return slow;
    }
    return NULL;
}

Node *begningLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *intersection = FloydLoopDetection(head);
    Node *temp = head;
    while (temp != intersection)
    {
        temp = temp->next;
        intersection = intersection->next;
    }
    return temp;
}

void removeLoop(Node *head)
{
    if (head == NULL)
        return;

    Node *startLoop = begningLoop(head);
    Node *temp = startLoop;
    while (temp->next != startLoop)
        temp = temp->next;

    temp->next = NULL;
}

int main()
{
    Node *head = new Node(34);
    Node *node2 = new Node(76);
    Node *node3 = new Node(21);
    Node *node4 = new Node(98);
    Node *node5 = new Node(76);
    Node *node6 = new Node(52);
    Node *node7 = new Node(87);
    Node *node8 = new Node(45);
    Node *node9 = new Node(19);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node4;

    if (FloydLoopDetection(head) != NULL)
    {
        cout << "Loop is present." << endl;
        cout << "The begning of loop is " << begningLoop(head)->data << endl;
    }
    else
        cout << "Loop is not present." << endl;

    removeLoop(head);

    if (FloydLoopDetection(head) != NULL)
    {
        cout << "Loop is present." << endl;
        // cout << "The begning of loop is " << begningLoop(head)->data << endl;
    }
    else
        cout << "Loop is not present." << endl;

    delete (head);
    delete (node2);
    delete (node3);
    delete (node4);
    delete (node5);
    delete (node6);
    delete (node7);
    delete (node8);
    delete (node9);
    return 0;
}