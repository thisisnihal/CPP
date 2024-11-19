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
 
// Date: 2024-11-01 20:05:14 IST
// Author: mailfornihalkr@gmail.com
void solve()
{
    int n;
    cin >> n;
    int ct0 = 0, ct1 = 0, temp;
    for (int i = 0; i < 2*n; i++)
    {
        cin >> temp;
        if (temp == 0) ct0++;
        else ct1++;
    }
    int mn = n - (ct0 / 2 + ct1 / 2);
    int mx = min(ct0, ct1);
    cout << mn << " " << mx << ed;
}
 
int main()
{
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}