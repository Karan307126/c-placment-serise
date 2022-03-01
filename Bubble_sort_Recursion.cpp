#include <bits/stdc++.h>
using namespace std;

void BubbleSort(int *arr, int n)
{
    if (n == 1 || n == 0)
        return;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }

    BubbleSort(arr, n - 1);
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

    BubbleSort(arr, n);
    cout << "After sorting" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    return 0;
}