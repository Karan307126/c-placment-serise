#include <bits/stdc++.h>
using namespace std;

void Permutation(string str, int idx)
{
    // Base case
    if (idx >= str.length())
    {
        cout << str << endl;
        return;
    }

    // Recursion....
    for (int j = idx; j < str.length(); j++)
    {
        swap(str[idx], str[j]);
        Permutation(str, idx + 1);
        swap(str[idx], str[j]);
    }
}

int main()
{
    string str;
    cout << "Enter string : ";
    cin >> str;

    Permutation(str, 0);
    return 0;
}