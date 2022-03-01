/*You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D
matrix and do the rotation.

example:
Input : 1 2 3           Output: 7 4 1
        4 5 6    -->            8 5 2
        7 8 9                   9 6 3
*/

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
            swap(matrix[i][j], matrix[j][i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    rotate(matrix);
    return 0;
}