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
 
// Date: 2024-10-29 20:08:55 IST
// Author: mailfornihalkr@gmail.com
void solve()
{
    int k, q;
    cin >> k >> q;
    int a[k], n[q];
    int mn = INT_MAX;
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    for (int i = 0; i < q; i++)
    {
        cin >> n[i];
    }


    for (int i = 0; i < q; i++)
    {
        if (mn > n[i]) cout << n[i];
        else cout << mn  - 1;
        cout << " ";
    }
    cout << ed;
    
    
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