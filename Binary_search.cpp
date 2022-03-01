#include <bits/stdc++.h>
using namespace std;

int BinarySearch_R(int *arr, int start, int end, int key)
{
    int mid = start + (end - start) / 2;
    if (start > end) // Base - case --> 1
        return -1;
    else if (arr[mid] == key) // Base - case --> 2
        return mid;
    else if (arr[mid] > key)
        return BinarySearch_R(arr, start, mid - 1, key); // Recursive reletion
    else
        return BinarySearch_R(arr, mid + 1, end, key); // Recursive reletion
}

int binarySearch(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int main()
{
    int n;
    cout << "Enter number of element : ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter array elements" << endl;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter key value : ";
    cin >> key;

    int index = binarySearch(arr, n, key);

    cout << "The index of key is : " << index << endl;

    int index2 = BinarySearch_R(arr, 0, n - 1, key);

    cout << "The index of key is : " << index2 << endl;

    delete[] arr;
    return 0;
}