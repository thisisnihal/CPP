#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-10-30 18:36:52 */
using namespace std;


int dp[50][50];
int f(int i, int j, vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    if (i < 0 || j < 0) return 0;
    if (i >= m || j >= n || grid[i][j] == -1) return 0;
    if (grid[i][j] == 4) return 0;
    // if (i == m-1 && j == n-1) return 1;
    if (grid[i][j] == 2) return 1;
    if (dp[i][j] != -1) return dp[i][j];
    grid[i][j] = 4;
    return dp[i][j] = f(i+1, j, grid) + f(i, j+1, grid) + f(i-1, j, grid) + f(i, j-1, grid);
}

    int uniquePathsIII(vector<vector<int>>& grid) {
            memset(dp, -1, sizeof(dp));
            int m = grid.size();
            int n = grid[0].size();
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        return f(i, j, grid);
                    }
                }
            }
        return 0;
    }

int main()
{
    vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    int ans = uniquePathsIII(grid);
    cout << "ans = " << ans << ed;
    return 0;
}