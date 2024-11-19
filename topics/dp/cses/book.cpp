#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-11-21 17:54:40 */
using namespace std;

vector<vector<int>> dp;
vector<int> h, s;

// ll f(int i, int money) {

//     if (money <= 0 || i < 0) return 0;
//     if (dp[i][money] != -1) return dp[i][money];

//     ll ans = f(i-1, money);
//     if (money-h[i] >= 0)
//         ans = max(ans, f(i-1, money - h[i]) + 0LL + s[i]);
        
//     return dp[i][money] = ans;
// }

void f(int n, int x) {

    dp.resize(n+1, vector<int>(x+1, 0));

    for (int i = 1; i <= n; i++)
    {   
        for (int j = 1; j <= x; j++)
        {
            // if (i == 0 or j == 0)
            //     dp[i][j] = 0;
            if (j - h[i-1] >= 0)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-h[i-1]] + s[i-1]);
            else
                dp[i][j] = dp[i-1][j];
        }
        
    }
    
}

void solve()
{
    int n, x;
    // n = max no of books; 
    // x = max total price;
    cin >> n >> x;
    // h[i] = price of ith book;
    // s[i] = pages of ith book;
    h.resize(n), s.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    dp.resize(n+1, vector<int>(x+1));

    // price is our constraint;
    // pages is what we have to maximize;

    // ll ans = f(n-1, x);  // method - 1 
    // cout << ans << ed;

    f(n, x); // method - 2
    cout << dp[n][x] << ed;

    
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

