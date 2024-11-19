#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-11-21 14:43:26 */
using namespace std;




void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vector<int> dp(x+10, x+10);
    dp[0] = 0;
    for (int i = 1; i <= x; i++)
    {   
        for (int coin : coins)
        {
            if (i - coin >= 0) dp[i] =  min(dp[i], 1 + dp[i-coin]); 
        }
        
    }
    cout << (dp[x] <= x ? dp[x]: -1) << ed;
    
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

