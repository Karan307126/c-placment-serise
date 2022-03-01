#include <bits/stdc++.h>
using namespace std;

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Print array before swaping." << endl;
    print_array(arr, n);

    for (int i = 0; i < n; i += 2)
    {
        if (i + 1 < n)
            swap(arr[i], arr[i + 1]);
    }

    cout << "Print array after swaping." << endl;
    print_array(arr, n);
    return 0;
}