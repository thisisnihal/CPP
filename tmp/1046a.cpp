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

// Date: 2025-08-28 20:01:32 IST
// Author: mailfornihalkr@gmail.com
bool valid(int x, int y) {
    return max(x, y) <= 2 * (min(x, y) + 1);
}
void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (valid(a, b) && valid(c - a, d - b))
        cout << "YES\n";
    else
        cout << "NO\n";
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
    while (t--)
    {
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cerr << "Execution Time: " << duration.count() << " ms" << std::endl;
    return 0;
}