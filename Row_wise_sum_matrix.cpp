#include <bits/stdc++.h>
using namespace std;

void Printsum(int arr[][5], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum = sum + arr[i][j];
        }
        cout << "The sum of " << i + 1 << " row is : " << sum << endl;
    }
}

void PrintsumCol(int arr[][5], int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += arr[j][i];
        }
        cout << "The sum of " << i + 1 << " column is : " << sum << endl;
    }
}

int main()
{
    int arr[3][5];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
            cin >> arr[i][j];
    }
    cout << endl;
    Printsum(arr, 3, 5);
    cout << endl;
    PrintsumCol(arr, 3, 5);
    return 0;
}