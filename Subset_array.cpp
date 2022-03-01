#include <bits/stdc++.h>
using namespace std;

void Subset(vector<int> input, vector<int> ans, int idx)
{
    // Base case
    if (idx >= input.size())
    {
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
        return;
    }
    // Exclude number
    Subset(input, ans, idx + 1);

    // Include number
    ans.push_back(input[idx]);
    Subset(input, ans, idx + 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> output;
    Subset(arr, output, 0);
    return 0;
}