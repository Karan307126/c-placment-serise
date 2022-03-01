#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr, int n)
{
    // Write your code here.
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }
    for (int i = 1; i < arr.size(); i++)
    {
        ans = ans ^ i;
    }
    return ans;
}

vector<int> findDuplicates(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<int> arr;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == nums[i + 1])
            arr.push_back(nums[i]);
    }

    return arr;
}

int main()
{
    vector<int> arr = {1};
    vector<int> ans = findDuplicates(arr);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}