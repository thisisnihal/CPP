#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-05-10 22:25:25 */
using namespace std;
    vector<vector<int>> subsets(vector<int>& nums) {
     int n = nums.size();
     int no_of_subsets = (1 << n); // = 2^n = number of subsets
     vector<vector<int> > subsets;
     for (int mask = 0; mask < no_of_subsets; mask++)
     {
        vector<int> subset;
        for (int i = 0; i < n; i++)
            if ( (mask & (1 << i)) != 0) subset.push_back(nums[i]);
        subsets.push_back(subset);
     }
     return subsets;
    }
int main()
{
    
    return 0;
}