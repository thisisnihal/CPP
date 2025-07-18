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
 
// Date: 2024-10-29 20:28:58 IST
// Author: mailfornihalkr@gmail.com

void precompute() {
    ull n = 1e18+1;
    ull l = -1, r = -1;
    if (n == 1) cout << 1 << ed;
    for (ull i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (l != -1) {
                r = i;
                break;
            }
            l = i;
        }
    }
}

void solve()
{
    


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