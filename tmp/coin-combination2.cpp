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
 
// Date: 2024-11-20 22:12:35 IST
// Author: mailfornihalkr@gmail.com

vector<int> coins;
vector<int> dp;
// vector<vector<int>> dp;
const int M = 1e9+7;

// int f(int i, int x) {

//     if (x < 0) return 0;
//     if (i < 0) return 0;
//     if (x == 0) return 1;
//     if (dp[i][x] != -1) return dp[i][x];

//     ll ways = f(i, x-coins[i]) + f(i-1, x);
    
//     return dp[i][x] = ways % M;
// }

int f2(int x) {
    if (x == 0) return 1; // Base case
    if (x < 0) return 0;  // Invalid state
    if (dp[x] != -1) return dp[x];

    int ways = 0;
    for (int coin : coins) {
        ways = (ways + f2(x - coin)) % M;
    }
    return dp[x] = ways;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    coins.resize(n);
    for(auto&it:coins) cin >> it;



    // dp.resize(n+1, vector<int>(x+1, -1));
    // int ways = f(n-1, x);
    dp.resize(x+1, -1);
    int ways = f2(x);
    cout << (ways) << ed;

    // dp.resize(x+1, 0);
    // dp[0] = 1;
    // int ways = 0;
    // for(int coin : coins) {
    //     for (int amnt = coin; amnt <= x; amnt++)
    //     {
    //         if (amnt - coin >= 0)
    //             dp[amnt] = (dp[amnt] + 0LL + dp[amnt - coin]) % M;
    //     }
    // }
    // cout << dp[x] << ed;

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
    cerr << "Execution Time: " << duration.count() << " ms" << std::endl;
    return 0;
}