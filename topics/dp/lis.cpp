#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-11-02 20:36:55 */
using namespace std;


int dp[2600];
int mx[1000];
int lis(int i, vector<int>& nums) {
    if (dp[i] != -1) return dp[i];
    int len = 1;
    for (int j = 0; j < i; j++)
    {
       if (nums[i] > nums[j]) 
        len = max(len, lis(j, nums)+1);
    }
    return dp[i] = len;
}

int main()
{
    vector<int> nums = {1,3,5,4,7};
    memset(dp, -1, sizeof(dp));
    memset(mx, 0, sizeof(mx));
    int mxlen = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        mxlen = max(mxlen, lis(i, nums));
    }
    cout << mxlen << ed;
     for (int i = 0; i < nums.size(); i++)
    {
        cout << dp[i] << ed;    
    }
    
    return 0;
}