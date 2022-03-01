#include <bits/stdc++.h>
using namespace std;

int factor(vector<int> arr)
{
    int num = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        num = num * 10 + arr[i];
    }
    return num;
}

int main()
{
    vector<int> a = {1, 2, 3, 4};
    vector<int> b = {4, 5, 6};
    int sum = factor(a) + factor(b);
    vector<int> ans;
    while (sum != 0)
    {
        ans.push_back(sum % 10);
        sum /= 10;
    }

    for (int i = 0; i < ans.size() / 2; i++)
        swap(ans[i], ans[ans.size() - i - 1]);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}