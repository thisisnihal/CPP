#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define ulld unsigned long long double
#define pb push_back
#define ppb pop_back
#define sz size()
#define ed "\n"
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
 
using namespace std;
 
// Date: 2024-12-21 20:39:00 IST
// Author: mailfornihalkr@gmail.com


const static int M = 1e9+7;
int K, m, n;
int ct = 0;
unordered_map<int, unordered_map<int, unordered_map<int, int>>> memo;
int f (int i, int j, int prev,  vector<vector<int>>& grid) {
    if (i < 0 || j < 0) return;
    int curr = grid[i][j];
    if (prev != -1) curr = curr ^ prev;
    if (i == 0 && j == 0) {
        if (curr == K) return ct = (ct+1) % M;
        return;
    }
    if (memo[i][j][prev]) 
    f(i-1, j, curr, grid);
    f(i, j-1, curr, grid);
        
}
int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
    K = k;
    m = grid.size(), n = grid[0].size();
    f(0,0, -1, grid);
    
    return ct;
}
void solve()
{
    vector<vector<int>> grid = {{2,1,5},{7,10,0},{12,6,4}};
    int k = 11;
    int ans = countPathsWithXorValue(grid, k);
    cout << ans << ed;
}
 
int main()
{
ios::sync_with_stdio(false);
cin.tie(NULL);
auto start = chrono::high_resolution_clock::now();
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // cerr << "Execution Time: " << duration.count() << " ms" << std::endl;
    return 0;
}