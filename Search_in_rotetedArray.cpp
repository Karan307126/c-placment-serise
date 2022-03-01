#include <bits/stdc++.h>
using namespace std;

int getPivot(vector<int> &arr, int n)
{
    int s = 0;
    int e = n - 1;

    while (s < e)
    {
        int mid = s + (e - s) / 2;

        if (arr[mid] >= arr[0])
            s = mid + 1;
        else
            e = mid;
    }
    return s;
}

int binarySearch(vector<int> &arr, int s, int e, int key)
{
    int start = s;
    int end = e;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
            return mid;

        // go to right wala part
        if (key > arr[mid])
            start = mid + 1;

        else
            end = mid - 1;
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cin >> key;

    int pivot = getPivot(arr, n);

    if (key >= arr[pivot] && key <= arr[n - 1])
        cout << binarySearch(arr, pivot, n - 1, key) << endl;

    else
        cout << binarySearch(arr, 0, pivot - 1, key) << endl;

    return 0;
}