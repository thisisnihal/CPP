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
 
// Date: 2024-11-22 01:14:10 IST
// Author: mailfornihalkr@gmail.com

const int N = 1e6+1, M = 1e9+10;
vector<int> dp(N, -1);


int f(int i) {
    if (i == 0) return dp[0] = 1;
    if (i < 0) return 0;
    if (dp[i] != -1) return dp[i];

    return dp[i];
}

void precompute() {
    f(10000);
}
void solve()
{
    int n;
    cin >> n;

    cout << dp[n] << ed;


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
    cin >> t;
    precompute();
    while (t--) {
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // cerr << "Execution Time: " << duration.count() << " ms" << std::endl;
    return 0;
}