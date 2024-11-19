#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2023-05-25 00:55:01 */
using namespace std;

// https://leetcode.com/problems/flood-fill/

void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid)
{
    int r = grid.size();
    int c = grid[0].size();
    if (i < 0 || j < 0 || i >= r || j >= c) return;
    if (grid[i][j] == '0') return;
    if (vis[i][j]) return;

    vis[i][j] = true;
    dfs(i - 1, j, vis, grid);
    dfs(i + 1, j, vis, grid);
    dfs(i, j - 1, vis, grid);
    dfs(i, j + 1, vis, grid);


    // diagonal calls
    // dfs(i-1, j - 1, vis, grid);
    // dfs(i-1, j + 1, vis, grid);
    // dfs(i+1, j - 1, vis, grid);
    // dfs(i+1, j + 1, vis, grid);


}
int numIslands(vector<vector<char>> &grid)
{

    int r = grid.size();
    int c = grid[0].size();
    vector<vector<bool>> vis(r, vector<bool>(c, false));

    int connnected_components = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if ((!vis[i][j]) and (grid[i][j] == '1'))
            {
                dfs(i, j, vis, grid);
                connnected_components++;
            }
        }
    }
    return connnected_components;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    cout << "hemlo" << ed;
    vector<vector<char>> grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    int n = numIslands(grid);
    cout << "n = " << n << ed;
    return 0;
}
