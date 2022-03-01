#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

node *findMid(node *head)
{
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node *merge(node *left, node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    node *ans = new node(-1);
    node *temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}

node *mergeSort(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    node *mid = findMid(head);

    node *left = head;
    node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    node *ans = merge(left, right);

    return ans;
}

void display(node *head)
{
    if (head != NULL)
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

int main()
{
    node *head = new node(5);
    node *node1 = new node(2);
    node *node2 = new node(6);
    node *node3 = new node(1);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    display(head);
    node *ans = mergeSort(head);
    display(ans);

    delete (head);
    delete (node1);
    delete (node2);
    delete (node3);
    delete (ans);
    return 0;
}