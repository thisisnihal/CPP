#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2024-02-18 22:54:44 */
using namespace std;

vector<bool> dp;
bool f(int i, vector<int> &nums)
{
    if (dp[i])
        return true;
    if (i >= nums.size() - 1 || nums[i] + i >= nums.size() - 1)
        return dp[i] = true;
    if (nums[i] == 0)
        return dp[i] = false;

    for (int j = 1; j <= nums[i]; j++)
    {
        dp[i+j] = f(i + j, nums);
    }
    return dp[i];
}

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    dp.resize(n, false);
    bool b = f(0, nums);
    for (bool t : dp)
    {
        if (t)
            return t;
    }
    return b;
}

void solve()
{
    vector<int> nums = {3,0,8,2,0,0,1};
    bool ans = canJump(nums);
    cout << "ans = " << ans << ed;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >>t;
    while (t--)
        solve();
    return 0;
}
