#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-11-21 16:28:04 */
using namespace std;
const int M = 1e9+7;

vector<int> dp;
// method - 1
// ll f(int n) {
//     if (n < 0) return 0;
//     if (dp[n] != -1) return dp[n];
//     ll ways = 0;
//     for (int i = 1; i <= 6; i++)
//     {
//         ways += 0LL+f(n-i);
//     }
//     return dp[n] = ways % M;   
// }

void solve()
{
    int n;
    cin >> n;
    dp.resize(n+2, 0);
    dp[0] = 1;

// method -1 
    // int ans = f(n);

// method - 2
// ---------------------------------------------
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= min(i, 6); j++)
        {
            dp[i] = (dp[i] + 0LL + dp[i-j]) % M;
        }
    }
// ---------------------------------------------
    cout << dp[n] << ed;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);   
freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >>t;
    while(t--)solve();
    return 0;
}

