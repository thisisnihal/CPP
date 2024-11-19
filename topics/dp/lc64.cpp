#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2023-10-29 22:49:24 */
using namespace std;

vector<vector<int>> dp;
int f(int i, int j, vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if (i == n - 1 && j == m - 1)
        return grid[i][j];
    if (i >= n || j >= m)
        return 1e7+10;
    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = min(grid[i][j] + f(i + 1, j, grid), grid[i][j] + f(i, j + 1, grid));
}
int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    dp.resize(n, vector<int>(m, -1));
    return f(0, 0, grid);
}

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int n = grid.size();
    int m = grid[0].size();
    int ans = minPathSum(grid);
    cout << "ans = " << ans << ed;
    return 0;
}