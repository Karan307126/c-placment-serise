#include <bits/stdc++.h>
using namespace std;

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void sortOne(int arr[], int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] == 0)
            i++;
        else if (arr[j] == 1)
            j--;
        else
        {
            swap(arr[i], arr[j]);
        }
    }
}

int main()
{
    int arr[10] = {1, 0, 1, 1, 1, 0, 1, 0, 0, 0};
    print_array(arr, 10);
    sortOne(arr, 10);
    print_array(arr, 10);
    return 0;
}