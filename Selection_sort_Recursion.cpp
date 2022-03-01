#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int *arr, int n)
{
    if (n == 0 || n == 1)
        return;

    int minIdx = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[minIdx] > arr[i])
            minIdx = i;
    }
    swap(arr[minIdx], arr[0]);

    SelectionSort(arr + 1, n - 1);
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

    SelectionSort(arr, n);
    cout << "After sorting" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    return 0;
}