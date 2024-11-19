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
 
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    if (s[0] == '1' || s[n-1] == '1') cout <<"YES" <<ed;
    else {
        for (int i = 1; i < n; i++) {
            if (s[i-1] == s[i] && s[i-1] == '1') {
                cout << "YES" << ed;
                return;
            }
        }
        cout << "NO" << ed;
    }
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