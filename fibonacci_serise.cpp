#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 0, b = 1, n;
    cout << "Enter the number : ";
    cin >> n;
    cout << a << " " << b << " ";
    for (int i = 0; i < n - 2; i++)
    {
        int fib = a + b;
        cout << fib << " ";
        a = b;
        b = fib;
    }
    return 0;
}