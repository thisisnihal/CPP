#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-08-21 00:58:40 */
using namespace std;

    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> s;
        int head, tail;
        long long mx = 0, sum = 0;
        for (head = 0, tail = 0; head < nums.size(); head++)
        {
            while ((s.find(nums[head]) != s.end() && tail <= head) or ((int)s.size() >= k))
            {
                mx = max(mx, sum);
                sum -= nums[tail];
                s.erase(nums[tail]);
                tail++;
            }
            s.insert(nums[head]);
            sum += nums[head];
            
        }
        return mx;
    }


int main()
{
    vector<int> nums = {1,5,4,2,9,9,9};
    int k = 3;
    long long ans = maximumSubarraySum(nums, k);
    cout << "ans = " << ans << ed;
    return 0;
}