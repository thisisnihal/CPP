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
 
// Date: 2024-11-19 21:20:35 IST
// Author: mailfornihalkr@gmail.com

int M = 1e9+7;
vector<int> dp;
int f(int i) {

    if (i < 0) return 0;
    if (i == 0) return dp[i%6] = 1;
    if (dp[i%6] != -1) return dp[i%6];

    ull ways = 0;
    for (int j = 1; j <= 6; j++)
    {
        ways +=  0LL + f(i-j);
    }
    return dp[i%6] = ways % M;
}

void solve()
{
    int n;
    cin >> n;

    dp.resize(7, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= min(i, 6); j++)
        {
            dp[i%6] = (dp[i%6] + 0LL + dp[(i-j)%6]) % M;
        }
        
    }

    cout << dp[n%6] << ed;

    // cout << f(n) <<  endl;
}
 
int main() {
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