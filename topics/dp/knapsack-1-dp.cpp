#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-10-17 02:08:45 */
using namespace std;

int wt[105], val[105];
long long dp[105][100005];

long long knapsack(int idx, int wt_left) {

    if (wt_left == 0) return 0;
    if (idx < 0) return 0;
    if (dp[idx][wt_left] != -1) return dp[idx][wt_left];

    // do not choose the item at idx
    long long ans = knapsack(idx-1, wt_left);
    if (wt_left-wt[idx] >= 0)
        ans = max(ans, knapsack(idx-1, wt_left - wt[idx]) + val[idx]); // choose the item at idx
    return dp[idx][wt_left] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }

    cout << knapsack(n-1, w) << ed;

    return 0;
}