#include <bits/stdc++.h>
using namespace std;

long long int sqrtInt(int n)
{
    int start = 0;
    int end = n;
    long long ans = -1;

    while (start <= end)
    {
        long long int mid = start + (end - start) / 2;
        long long int squer = mid * mid;
        if (squer == n)
            return mid;
        else if (squer < n)
        {
            ans = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return ans;
}

double sqrtFloat(int n, int precision, int tempsol)
{
    double fraction = 1;
    double ans = tempsol;

    for (int i = 0; i < precision; i++)
    {
        fraction = fraction / 10;
        for (double j = ans; j * j < n; j = j + fraction)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;

    int precision;
    cout << "Enter precision : ";
    cin >> precision;

    int tempsol = sqrtInt(n);
    cout << "The squar root of " << n << " is = " << sqrtFloat(n, precision, tempsol) << endl;
    return 0;
}