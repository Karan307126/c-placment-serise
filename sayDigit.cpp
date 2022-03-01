#include <bits/stdc++.h>
using namespace std;

void sayDigit(int n, string arr[])
{
    if (n == 0)
        return;
    int digit = n % 10;
    sayDigit(n / 10, arr);
    cout << arr[digit] << " ";
}

int main()
{
    int n;
    cin >> n;
    string arr[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"};
    cout << endl;
    sayDigit(n, arr);
    return 0;
}