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
 
// Date: 2024-11-22 01:53:06 IST
// Author: mailfornihalkr@gmail.com

/* used LCS */
/* If only insertion and deletion are allowed */
void solve1()
{
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int lcs = dp[n][m];
    int insertion = m - lcs, deletion = n - lcs;
    int ops = (insertion + deletion);
    cout << ops << ed;
}

/* ANSWER FOR THIS CSES PROBLEM*/
/* IF insertion, deletion and replacement are alllower */
void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();

   auto min = [](int a, int b, int c) {
    return (a < b ? (a < c ? a : c) : (b < c ? b : c));
};

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
            }
        }
    }
    cout << dp[n][m] << ed;

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