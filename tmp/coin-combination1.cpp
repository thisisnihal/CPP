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

vector<int> dp, coins;
const int M = 1e9+7;

int f(int x) {

    if (x < 0) return 0;
    if (x == 0) return 1;
    if (dp[x] != -1) return dp[x];

    ll ways = 0;
    for(int coin: coins) {
        ways = (ways + f(x-coin)) % M;
    }
    return dp[x] = ways;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    // dp.resize(x+1, -1); 
    coins.resize(n);
    for(auto&it:coins) cin >> it;

    // int ways = f(x);
    // cout << (ways) << ed;

    dp.resize(x+1, 0);
    dp[0] = 1;
    int ways = 0;
    for(int coin : coins) {
        for (int amnt = coin; amnt <= x; amnt++)
        {
            if (amnt - coin >= 0)
                dp[amnt] = (dp[amnt] + 0LL + dp[amnt - coin]) % M;
        }
    }
    cout << dp[x] << ed;;


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






/** 
 * @return number of ways to make sum s using repeated coins
 */
int coinrep(auto& coins, int s) {
    int dp[s + 1]; 
    dp[0] = 1;          
    for (int coin : coins)      
        for (int i = coin; i <= s; i++)         
            dp[i] += dp[i - coin];                                  
    return dp[s];
}                                       
                                            
/**
 * @return number of ways to make sum s using non-repeated coins
 */
int coinnonrep(auto& coins, int s) {
    int dp[s + 1];
    dp[0] = 1;  
    for (int coin : coins)
        for (int i = s; i >= coin; i--)
            dp[i] += dp[i - coin];              
    return dp[s];                                                   
} 