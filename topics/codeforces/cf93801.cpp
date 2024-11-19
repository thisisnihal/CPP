#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2024-04-08 20:08:39 */
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    int ans = min(n * a, ((n / 2) * b + (n % 2) * a));
    cout << ans << ed;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
