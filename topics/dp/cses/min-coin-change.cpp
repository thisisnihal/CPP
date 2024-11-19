#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-11-21 16:02:19 */
using namespace std;






const static int N = 1e6+10; // max amount
int dp[N];
int f(int amount, vector<int>& coins){

    if (amount == 0) return 0;
    if (amount < 0) return INT_MAX;
    if (dp[amount] != -1) return dp[amount];

    int min_ways = INT_MAX;
    for (int x : coins) {
        min_ways = min(min_ways + 0LL, f(amount-x, coins) + 1LL);
    }
    return dp[amount] = min_ways;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) cin >> coins[i];

    int ans = f(x, coins);
    cout << (ans == INT_MAX ? -1 : ans) << ed;
    
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

