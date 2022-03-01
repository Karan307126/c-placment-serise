#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i = 0, ans = 0;

    while (n != 0)
    {
        int digit = n % 10;
        ans = ans + (pow(2, i) * digit);
        n = n / 10;
        i++;
    }
    cout << "Decimal number is : " << ans << endl;
    return 0;
}