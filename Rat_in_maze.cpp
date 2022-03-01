#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> maze, int n, int x, int y, vector<vector<bool>> visited)
{
    if (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == false && maze[x][y] == 1)
        return true;
    return false;
}

void findPath(vector<vector<int>> maze, int n, int x, int y, string path, vector<vector<bool>> visited)
{
    if (x >= n - 1 and y >= n - 1)
    {
        cout << path << endl;
        return;
    }

    visited[x][y] = true;
    int newx = x + 1;
    int newy = y;
    if (isSafe(maze, n, newx, newy, visited))
    {
        path.push_back('D');
        findPath(maze, n, newx, newy, path, visited);
        path.pop_back();
    }

    newx = x;
    newy = y - 1;
    if (isSafe(maze, n, newx, newy, visited))
    {
        path.push_back('L');
        findPath(maze, n, newx, newy, path, visited);
        path.pop_back();
    }

    newx = x;
    newy = y + 1;
    if (isSafe(maze, n, newx, newy, visited))
    {
        path.push_back('R');
        findPath(maze, n, newx, newy, path, visited);
        path.pop_back();
    }

    newx = x - 1;
    newy = y;
    if (isSafe(maze, n, newx, newy, visited))
    {
        path.push_back('U');
        findPath(maze, n, newx, newy, path, visited);
        path.pop_back();
    }

    visited[x][y] = false;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];
    }

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path = "";

    findPath(maze, n, 0, 0, path, visited);
    return 0;
}