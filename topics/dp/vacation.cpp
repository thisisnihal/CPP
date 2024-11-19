#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-10-16 04:21:33 */
using namespace std;

int main()
{
    int N;
    cin >> N;
    int arr[N][3];
    for (int i = 0; i < N; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    
    int dp[N][3];
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    for (int i = 1; i < N; i++)
    {
       dp[i][0] = arr[i][0] + max(dp[i-1][1], dp[i-1][2]);
       dp[i][1] = arr[i][1] + max(dp[i-1][0], dp[i-1][2]);
       dp[i][2] = arr[i][2] + max(dp[i-1][0], dp[i-1][1]);
    }
    
    cout << max(dp[N-1][0], max(dp[N-1][1], dp[N-1][2])) << ed;
    return 0;
}