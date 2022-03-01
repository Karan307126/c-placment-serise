#include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int s, int e)
{
    int pivot = arr[s];
    int i = e + 1;
    for (int j = e; j > s; j--)
    {
        if (arr[j] > pivot)
        {
            i--;
            swap(arr[i], arr[j]);
        }
    }
    i--;
    swap(arr[i], arr[s]);
    return i;
}

void QuickSort(int *arr, int s, int e)
{
    if (s < e)
    {
        int pivotIdx = partition(arr, s, e);
        QuickSort(arr, s, pivotIdx - 1);
        QuickSort(arr, pivotIdx + 1, e);
    }
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

    QuickSort(arr, 0, n - 1);
    cout << "After sorting" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;
    return 0;
}