#include <bits/stdc++.h>
using namespace std;

bool know(vector<vector<int>> m, int n, int a, int b)
{
    if (m[a][b] == 1)
        return true;
    return false;
}

int celebrity(vector<vector<int>> m, int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
        st.push(i);
    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        if (know(m, n, a, b))
            st.push(b);
        else
            st.push(a);
    }

    int ans = st.top();
    int zerocount = 0;
    for (int i = 0; i < n; i++)
    {
        if (m[ans][i] == 0)
            zerocount++;
    }
    if (zerocount != n)
        return -1;

    int onecount = 0;
    for (int i = 0; i < n; i++)
    {
        if (m[i][ans] == 1)
            onecount++;
    }
    if (onecount != n - 1)
        return -1;

    return ans;
}

int main()
{
    vector<vector<int>> arr = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    cout << "The celebrity is : " << celebrity(arr, 3) << endl;
    return 0;
}