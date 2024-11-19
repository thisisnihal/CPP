#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-11-27 00:18:05 */
using namespace std;

    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        if (hi == -1) return {-1,-1};

        bool found = false;
        int mid;
        while (lo <= hi) {
            mid = (lo+hi)/2;
            if (nums[mid] == target) {
                found = true;
                break;
            }
            else if (nums[mid] < target) lo = mid + 1;
            else hi = mid - 1; 
        }
        if (found) {
            int L, R;
            L = mid;
            R = mid;
            bool gotL = false, gotR = false;
            while (!gotL || !gotR) {
                if (!gotL && nums[L] == target) {
                    if (L == 0 || nums[L-1] != target) gotL = true;
                    else L--;
                }
                 if (!gotR && nums[R] == target) {
                    if (R == nums.size()-1 || nums[R+1] != target) gotR = true;
                    else R++;
                }
            }
            return {L, R};
        }
        return {-1,-1};
    }


int main()
{
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> ans = searchRange(nums, target);
    cout << ans[0] << " " << ans[1] << ed;
    return 0;
}