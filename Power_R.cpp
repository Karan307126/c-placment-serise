#include <bits/stdc++.h>
using namespace std;

int Power(int a, int b)
{
    if (b == 0)
        return 1;

    int ans = Power(a, b / 2);
    if (b % 2 == 0)
        return ans * ans;
    else
        return a * ans * ans;
}

int main()
{
    int a, b;
    cout << "Enter number a : ";
    cin >> a;
    cout << "Enter power : ";
    cin >> b;

    cout << "Power : " << Power(a, b) << endl;
    return 0;
}