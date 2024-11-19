#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2023-10-25 18:33:17 */
using namespace std;

int rob(vector<int> &nums)
{
    int n = nums.size();
    int dp[n+10];
    int ans = 0;
    dp[0] = 0, dp[1] = nums[0];
    for (int i = 1; i < n; i++)
    {
        dp[i+1] = max(dp[i], dp[i-1]+nums[i]);
    }
    return dp[n];
}

int main()
{
    vector<int> nums = {2,7,9,3,1};
    int ans = rob(nums);
    cout << ans << ed;
    return 0;
}