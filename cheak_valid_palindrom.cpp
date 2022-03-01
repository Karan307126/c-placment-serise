#include <bits/stdc++.h>
using namespace std;

char toLower(char s)
{
    if (s >= 'A' && s <= 'Z')
        s = s - 'A' + 'a';
    return s;
}

bool isPalindrome(string s)
{
    string str = ""; // Empty string
    int len = 0;     // will count length of the new string str
    for (int i = 0; s[i] != '\0'; i++)
    {

        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= '0' && s[i] <= '9'))
        {
            str += s[i];
            len++;
        }
    }

    int i = 0, j = len - 1;
    while (i <= j)
    {
        if (toLower(str[i++]) != toLower(str[j--]))
            return false;
    }
    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    bool ans = isPalindrome(s);
    cout << ans << endl;
    return 0;
}