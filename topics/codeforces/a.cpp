#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-12-03 20:46:15 */
using namespace std;



int f(int p, int l, int t) {
    int d = (p / (l+t));
    if (d != 0) return d;
    int a = p/l, b = p/t;
    if (a < b) return a;
    return b;
}

void solve()
{
    ull p;
    int n;
    int l, t;
    cin >> n >> p >> l >> t;
    int mxtheory = 1 + (n-1) / 7;
    double d = f(p, l, t); //  non_zero(floor(p / (l+t)), floor(p / (l)), floor(p / (t)));
    if (d > mxtheory) d = ((p - t * mxtheory) / l);
    int ans = ((n-d));
    cout << ans << ed;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >>t;
    while(t--)solve();
    return 0;
}

