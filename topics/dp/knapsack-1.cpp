#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-10-16 19:51:08 */
using namespace std;

int main()
{
    int N, W;
    cin >> N >> W;
    int w[N], v[N];
    for (int i = 0; i < N; i++) cin >> w[i] >> v[i];

    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (j-w[i]>= 0)
                dp[i][j] = max(dp[i-1][j], v[i]+dp[i-1][j-w[i]]);
        }
    }
    
cout << dp[N-1][W-1] << ed;
    return 0;
}
/*
6 15
6 5
5 6
6 4
6 6
3 5
7 2
*/

