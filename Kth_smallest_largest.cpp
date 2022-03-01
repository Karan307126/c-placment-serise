#include <bits/stdc++.h>
using namespace std;

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    vector<int> ans;
    sort(arr.begin(), arr.end());
    ans.push_back(arr[k - 1]);
    ans.push_back(arr[n - k]);
    return ans;
}

int main()
{
    vector<int> arr = {5, 10, 25, 13, 43, 34, 10};
    vector<int> ans = kthSmallLarge(arr, 7, 3);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}