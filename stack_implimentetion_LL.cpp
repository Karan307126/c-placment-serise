#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int data;
    Stack *next;

    Stack(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    void push(Stack *&top, int data)
    {
        Stack *temp = new Stack(data);
        if (top == NULL)
            top = temp;
        else
        {
            temp->next = top;
            top = temp;
        }
    }

    int pop(Stack *&top)
    {
        if (top == NULL)
        {
            cout << "Stack is underflow." << endl;
            return -1;
        }
        else
        {
            Stack *temp = top;
            int ans = top->data;
            top = top->next;
            delete (temp);
            return ans;
        }
    }

    int peek(Stack *top)
    {
        return top->data;
    }

    bool isEmpty(Stack *top)
    {
        if (top == NULL)
            return true;
        return false;
    }
};

int main()
{
    Stack *top = NULL;
    top->push(top, 4);
    top->push(top, 3);
    top->push(top, 1);
    cout << "Poped element is " << top->pop(top) << endl;
    cout << "Poped element is " << top->pop(top) << endl;
    cout << "The top of the stack is " << top->peek(top) << endl;
    delete (top);
    return 0;
}