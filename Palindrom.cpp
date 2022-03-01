#include <bits/stdc++.h>
using namespace std;

bool cheakPalindrom(string str, int s, int e)
{
    if (s > e)
        return true;
    else if (str[s] != str[e])
        return false;
    else
        return cheakPalindrom(str, s + 1, e - 1);
}

string binary(int n)
{
    int ans = 0, i = 0;
    while (n != 0)
    {
        int bit = n & 1;
        ans = bit * pow(10, i) + ans;

        n = n >> 1;
        i++;
    }
    return to_string(ans);
}

int main()
{
    int n;
    cout << "Enter number : " << endl;
    cin >> n;

    string str = binary(n);

    // cout << str << endl;

    if (cheakPalindrom(str, 0, str.length() - 1))
        cout << "This number's binary is palindrom." << endl;
    else
        cout << "This number's binary is not palindrom." << endl;
    return 0;
}