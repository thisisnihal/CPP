#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-08-17 14:02:31 */
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int head, tail, ans = 0;
    int product = 1;
    for (head = 0, tail = 0; head < nums.size(); head++) {
        product *= nums[head];
        while(product >= k) {
            product /= nums[tail];
            tail++;
        }
        ans += (head-tail+1);
    }
    return ans;
}

int main()
{
    vector<int> nums = {10,5,2,6};
    int k = 100;
    int a = numSubarrayProductLessThanK(nums, k);
    cout << "ans = " << a << ed;
    return 0;
}