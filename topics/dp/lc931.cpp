#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-10-30 20:47:26 */
using namespace std;



long long min(long long a,long long b,long long c) {
    if (a <= b and a <= c) return a;
    else if (b <= a and b <= c) return b;
    else return c;
}
long long min(long long a, long long b) {
    if (a <= b) return a;
    else return b;
}
vector<vector<long long>> dp;
long long f(int i, int j, vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if (i == n - 1) return grid[i][j];
    if (i >= n || j >= m) return 1e6+10;
    if (j < 0) return INT_MAX;
    if (dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = min(grid[i][j]+f(i + 1, j, grid),grid[i][j]+ f(i+1, j - 1, grid),grid[i][j]+ f(i+1, j+1, grid));
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    dp.resize(n, vector<long long>(m, -1));
    long long mn = INT_MAX;
    for (int i = 0; i < m; i++) {
        mn = min(mn, f(0, i, matrix));
        dp.resize(n, vector<long long>(m, -1));
    }
    return mn;
    }
int main()
{
    
    return 0;
}