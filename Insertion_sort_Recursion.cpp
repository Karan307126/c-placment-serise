#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int *arr, int n)
{
    if (n == 0 || n == 1)
        return;

    InsertionSort(arr, n - 1);

    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Before sorting" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl
         << endl;

    InsertionSort(arr, n);
    cout << "After sorting" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    return 0;
}