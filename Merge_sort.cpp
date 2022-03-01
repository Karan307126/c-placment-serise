#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int mid, int e)
{
    int *merged = new int[e - s + 1];

    int i = s, j = mid + 1, k = 0;
    while (i <= mid && j <= e)
    {
        if (arr[i] < arr[j])
            merged[k++] = arr[i++];
        else
            merged[k++] = arr[j++];
    }

    while (i <= mid)
        merged[k++] = arr[i++];

    while (j <= e)
        merged[k++] = arr[j++];

    for (int i = s; i <= e; i++)
        arr[i] = merged[i - s];
}

void MergeSort(int *arr, int s, int e)
{
    if (s < e)
    {
        int mid = s + (e - s) / 2;
        // For left
        MergeSort(arr, s, mid);
        // For right
        MergeSort(arr, mid + 1, e);
        // Merge
        merge(arr, s, mid, e);
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

    MergeSort(arr, 0, n - 1);
    cout << "After sorting" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}