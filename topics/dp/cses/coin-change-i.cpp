#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-11-21 12:09:04 */
using namespace std;

int M = 1e9+7;

vector<int> dp;

// long long f(int x, vector<int>& coins) {
//     if (x == 0) return 1;
//     if (dp[x] != -1) return 1;
//     long long ways = 0;
//     for (int coin : coins)
//     {   
//         if (x-coin >= 0) ways += f(x-coin, coins);
//     }

//     return dp[x] = ways % M;
// }

long long f(int x, vector<int>& coins) {
    if (x == 0) return 0;
    if (dp[x] != -1) return dp[x];
    long long ways = INT_MAX;
    for (int coin : coins)
    {   
        if (x-coin >= 0) ways = min(ways, 1+f(x-coin, coins));
    }

    return dp[x] = ways;
}


void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    dp.resize(x+10, -1);
    int ans = f(x, coins);
    cout << (dp[x] > x ? -1 : dp[x]) << ed;

}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >>t;
    // cout << "ans = \n";
    // cout << "ans = ";
    while(t--)solve();
    return 0;
}

