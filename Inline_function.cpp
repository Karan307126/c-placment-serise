#include <bits/stdc++.h>
using namespace std;

inline int Findmax(int &a, int &b) // inline function is contain only 2-3 line....
{
    return (a > b) ? a : b;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << Findmax(a, b) << endl;
    return 0;
}