#include <bits/stdc++.h>
using namespace std;

void solve(string &str, int start, int end)
{
    if (start > end)
        return;
    swap(str[start], str[end]);
    return solve(str, start + 1, end - 1);
}

int main()
{
    string str;
    cin >> str;

    solve(str, 0, str.length() - 1);
    cout << str << endl;
    return 0;
}