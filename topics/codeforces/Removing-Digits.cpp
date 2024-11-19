#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-11-16 00:56:26 */
using namespace std;

vector<int> getDigits(int n) {
    vector<int> a;
    if (n == 0) return {0};
    while(n > 0) {
        int r = n % 10;
        n /= 10;
        a.push_back(r);
    }
    return a;
}

vector<int> dp;
int f(int num, vector<int> digits) {

    if (dp[num] != -1) return dp[num];

    int ans = INT_MAX;
    for (int digit : digits) {
        if (digit == 0 ) continue;
        ans = min(ans, f(num-digit, getDigits(num-digit))+1);
    }
    dp[num] = ans == INT_MAX ? 0 : ans;
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> digits;
    digits = getDigits(n);
    dp.resize(n+10, -1);
    dp[0] = 0;
    int ans = f(n, digits);
    cout << ans << ed;

    // for (int e : digits) cout << e << " ";
}

int main()
{
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}