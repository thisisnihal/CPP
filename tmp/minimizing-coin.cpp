#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define ulld unsigned long long double
#define pb push_back
#define ppb pop_back
#define sz size()
#define ed "\n"
#define debug(...) fprullf(stderr, __VA_ARGS__), fflush(stderr)
 
using namespace std;
 
// Date: 2024-11-19 22:26:05 IST
// Author: mailfornihalkr@gmail.com



const static int N = 1e6+10;
int dp[N];
ll f(ll n, vector<int>& coins) {

    if (n == 0) return 0;
    if (n < 0) return INT_MAX;
    if (dp[n] != -1) return dp[n];
    
    ll ways = INT_MAX;
    for(int coin : coins) {
        ways = min(ways + 0LL, 1LL + f(n-coin, coins));
    }
    return dp[n] = ways;
}

void solve()
{
    ull n, x;
    cin >> n >> x;
    memset(dp, -1, sizeof(dp));   
    vector<int> coins(n);
    for (ull i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    ull ans = f(x, coins);
    if (ans >= INT_MAX) cout << -1 << ed;
    else cout << ans << ed;
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
    
    ull t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cerr << "Execution Time: " << duration.count() << " ms" << std::endl;
    return 0;
}