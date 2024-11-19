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

// Date: 2024-11-02 13:23:26 IST
// Author: mailfornihalkr@gmail.com
void solve()
{
    int n, k;
    cin >> n >> k;
    if (n == 1 && k == 1)
    {
        cout  << 1 << ed;
        cout << 1 << ed;
        return;
    }
    if (n > 1 && (k == 1 ||  k == n)) {
        cout << -1 << ed;
        return;
    }

    if (k % 2 == 0) {
        cout << 3 << ed;
        cout << 1 << " " << k << " " << k+1 << ed;
    } else {
        cout << 5 << ed;
        cout << 1 << " " << k-1 << " " << k << " " << k+1 << " " << k+2 << ed;
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
    while (t--)
    {
        solve();
    }
    return 0;
}