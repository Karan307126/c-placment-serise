#include <bits/stdc++.h>
using namespace std;

bool lenearSearch_R(int arr[], int n, int key)
{
    if (n == 0)
        return false;
    else if (arr[0] == key)
        return true;
    return lenearSearch_R(arr + 1, n - 1, key);
}

bool lenear_search(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (key = arr[i])
            return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cin >> key;

    // Recursive search....
    if (lenearSearch_R(arr, n, key))
        cout << "Key value is present." << endl;
    else
        cout << "Key value is absent." << endl;

    // Itretive search....
    // if (lenearSearch_R(arr, n, key))
    //     cout << "Key value is present." << endl;
    // else
    //     cout << "Key value is absent." << endl;

    delete[] arr;
    return 0;
}