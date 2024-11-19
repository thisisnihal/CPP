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
    int N;
    cin >> N;
    int h[N];
    for (int i = 0; i < N; i++) cin >> h[i];
    
    int dp[N];
    dp[0] = 0, dp[1] = abs(h[1]-h[0]);
    for (int i = 2; i < N; i++) 
    {
        dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));
    }
    
    cout << dp[N-1] << ed;
    return 0;
}