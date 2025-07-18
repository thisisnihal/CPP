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
#define fast_io ios::sync_with_stdio(false); cin.tie(NULL);
 
using namespace std;
 
// Date: 2024-11-02 20:32:45 IST
// Author: mailfornihalkr@gmail.com
void solve()
{
    int n;
    cin >> n;
    int a[n];
    string s = "YES";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i != 0) {
            int diff = abs(a[i] - a[i-1]);
            if (diff != 5 && diff != 7) {
                s = "NO";
            }
        }
    }
    cout << s << ed;
    
}
 
int main()
{
fast_io;
 
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