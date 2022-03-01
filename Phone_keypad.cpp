#include <bits/stdc++.h>
using namespace std;

void phoneKeypad(string digit, string output, int idx, string mapping[])
{
    // Base case --> print output string and return.
    if (idx >= digit.length())
    {
        cout << output << endl;
        return;
    }

    int num = digit[idx] - '0'; // Take a number into string digit.
    string val = mapping[num];  // Taking string from mapping[] coresponding number.

    for (int i = 0; i < val.length(); i++)
    {
        output.push_back(val[i]);
        phoneKeypad(digit, output, idx + 1, mapping);
        output.pop_back();
    }
}

int main()
{
    string digit;
    cout << "Enter keypad digits : ";
    cin >> digit;

    string output = "";
    string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    phoneKeypad(digit, output, 0, mapping);
    return 0;
}