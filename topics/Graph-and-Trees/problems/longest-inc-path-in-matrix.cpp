#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2023-05-25 16:35:05 */
using namespace std;

int mx = INT_MIN;
void dfs(int i, int j, int len, int curr, vector<vector<bool>> &vis, vector<vector<int>> &matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();
    if (i < 0 || j < 0 || i >= r || j >= c) return;
    if (matrix[i][j] <= curr) return;
    if (vis[i][j]) return;

    vis[i][j] = true;
    curr = matrix[i][j];
    len++;
    mx = max(mx, len);
    dfs(i - 1, j, len, curr, vis, matrix);
    dfs(i + 1, j, len, curr, vis, matrix);
    dfs(i, j - 1, len, curr, vis, matrix);
    dfs(i, j + 1, len, curr, vis, matrix);
}

int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();

    vector<vector<bool>> vis(r, vector<bool>(c, false));
    int len = 0;
   
    int slno = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            len = 0;
            dfs(i, j, len, INT_MIN, vis, matrix);

            for (int i = 0; i < r; i++)
                fill(vis[i].begin(), vis[i].end(), false);

            //mx = max(len, mx);
            cout << slno++ << ". len:" << mx << ed;
            
        }
    }
    return mx;
}

void solve()
{
    vector<vector<int>> matrix = {
        {7,8,9},
        {9,7,6},
        {7,2,3} }; //{{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    int ans = longestIncreasingPath(matrix);
    cout << ans << ed;
}

int main()
{
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    int t = 1;
    // cin >>t;
    while (t--)
        solve();
    return 0;
}

//  fill(vis.begin(), vis.end(), false); // that works for 1D vector.

// that will work for 2d vector.
// for (auto &i : x)
//     std::fill(i.begin(), i.end(), 0);
// or
// for(auto& v : x)
//     std::memset(&v[0], 0, sizeof(v[0]) * v.size());