#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-10-15 16:39:34 */
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int h[N];
    for (int i = 0; i < N; i++) cin >> h[i];
    
    int dp[N];
    for (int i = 0; i < N; i++) dp[i] = INT_MAX;
    dp[0] = 0;

    for (int i = 1; i < N; i++)
    {   
        for (int j = 1; i-j >= 0 and j <= K; j++)
        {
            dp[i] = min(dp[i], dp[i-j]+abs(h[i]-h[i-j]));
        }
    }
    
    cout << dp[N-1] << ed;
    return 0;
}