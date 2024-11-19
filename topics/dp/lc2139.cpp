#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-10-27 17:06:49 */
using namespace std;



    vector<int> memo;
    int f(int x, int t, int mxD) {
        if (x == t) return 0;
        if (x > t) return INT_MAX-1;
        if (memo[x] != -1) return memo[x];
        if (mxD <= 0) return 1+f(x+1, t, mxD);

        return memo[x]=min(1+f(x+1, t, mxD), 1+f(x*2, t, mxD-1));
    }

    int minMoves(int target, int maxDoubles) {
        memo.resize(10000, -1);
        return f(1, target, maxDoubles);
    }


int main()
{
    int t,  mxD;
    cin >> t >>  mxD;
    int ans = minMoves(t, mxD);
    cout << "ans  = " << ans << ed;
    return 0;
}