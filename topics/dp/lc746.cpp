#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-10-28 23:44:50 */
using namespace std;



    vector<int> memo;
    int f(int i, vector<int>& cost) {
        if(i>=cost.size()) return 0;
        if (memo[i] != -1) return memo[i];

        return memo[i] = min(cost[i]+f(i+1, cost), cost[i]+f(i+2, cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memo.resize(cost.size()+10, -1);
        return min(f(0, cost), f(1, cost));
        
    }

int main()
{
    vector<int> cost = {10,15,20};
    int ans = minCostClimbingStairs(cost);
    cout << "ans = " << ans << ed;
    return 0;
}