#include <bits/stdc++.h>
using namespace std;

int main()
{
    // single element allocate memory in heap....
    // char c;
    // int *n1 = new int(5);
    // char *ch = new char(c);
    // cin >> c;
    // cout << *n1 << endl;
    // cout << c << endl;
    // delete ch;
    // delete n1;

    // Array allocate memory in heap....
    // int num;
    // cin >> num;
    // int *arr = new int[num];
    // for (int i = 0; i < num; i++)
    //     cin >> arr[i];

    // for (int i = 0; i < num; i++)
    //     cout << arr[i] << " ";

    // delete []arr;

    // 2D array allocate memory in heap....
    int n, m;
    cin >> n >> m;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    // Free allocated 2D array's memory....
    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}