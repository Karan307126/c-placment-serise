#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int> arr){
    int start = 0, end = arr.size() - 1;

    while(start < end){
        int mid = start + (end - start) / 2;

        if(arr[mid] >= arr[0])
            start = mid + 1;
        else
            end = mid;
    }

    return start;
}

int main()
{
    vector<int> arr = {12, 13, 15, 18, 29, 31, 0, 2, 4, 5, 7, 10, 11};

    cout << "The index of pivot element is : " << findPivot(arr) << endl;
    cout << "The pivot element is : " << arr[findPivot(arr)] << endl;

    return 0;
}