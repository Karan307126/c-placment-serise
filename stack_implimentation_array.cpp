#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        this->arr = new int[size];
        this->top = -1;
    }

    void push(int num)
    {
        if (size - top > 1)
            arr[++top] = num;
        else
            cout << "Stack overflow." << endl;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack is underflow." << endl;
            return -1;
        }
        else
        {
            int ans = arr[top];
            top--;
            return ans;
        }
    }

    int peek()
    {
        return arr[top];
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        return false;
    }
};

int main()
{
    Stack st(5);
    st.push(4);
    st.push(3);
    st.push(1);
    cout << "Poped element is " << st.pop() << endl;
    cout << "Poped element is " << st.pop() << endl;
    cout << "The top of the stack is " << st.peek() << endl;
    return 0;
}