#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define ulld unsigned long long double
#define pb push_back
#define ppb pop_back
#define sz size()
#define ed "\n"
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
 
using namespace std;
 
int longestConsecutive(vector<int>& nums) {

    if (nums.size() == 0) return 0;
    set<int> st;
    for (int num : nums) st.insert(num);

    int mx = 1, prev, curr_mx = 1;
    for (auto it = st.begin(); it != st.end(); it++) {
        if (it == st.begin()) {
            prev = *it;
            continue;
        }
        int curr = *it;
        if (prev + 1 == curr) {
            curr_mx++;
            mx = max(mx, curr_mx);
        } else {
            curr_mx = 1;
        }
        prev = curr;
    }
    return mx;
}
int main()
{
    vector<int> nums = {9,1,4,7,3,-1,0,5,8,-1,6};
    int ans = longestConsecutive(nums);
    cout << "ans = " << ans << ed;
}