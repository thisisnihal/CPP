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
 
// Date: 2024-11-15 19:03:06 IST
// Author: mailfornihalkr@gmail.com
void solve() {
    int n;
    int curr, prev, mx = INT_MIN;
    cin >> n >> prev;
    mx = prev;
    bool flag = false;
    for (int i = 1; i < n; i++) {
        cin >> curr;
        mx = max(mx, curr);
        if (prev - curr > 1 || mx - curr > 1) flag = true;
        prev = curr;
    }
    if (flag) cout << "NO" << ed;
    else cout << "YES" << ed;
}
int main()
{
ios::sync_with_stdio(false);
cin.tie(NULL);
auto start = chrono::high_resolution_clock::now();
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // cerr << "Execution Time: " << duration.count() << " ms" << std::endl;
    return 0;
}