#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-11-21 17:17:40 */
using namespace std;

int M = 1e9+7;
vector<vector<int>> dp;
ll f(int i, int j, vector<vector<char>>& grid) {
    int n = grid.size(); 
    if (i >= n || j >= n) return 0;
    if (grid[i][j] == '*') return 0; 
    if (i == n-1 && j == n-1) return 1;
    if (dp[i][j] != -1) return dp[i][j];
    

    return dp[i][j] = (f(i+1, j, grid) + 0LL + f(i, j+1, grid)) % M;

}

void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    dp.resize(n+10, vector<int>(n+10, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }


    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << grid[i][j];
    //     }
    //     cout << ed;
    // }

    int ans = f(0, 0, grid);
    // cout << "ans = ";
    cout << ans;
        
}

int main()
{
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif
    int t = 1;
    //cin >>t;
    while(t--)solve();
    return 0;
}

