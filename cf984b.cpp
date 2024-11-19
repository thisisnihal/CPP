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

// Date: 2024-11-02 21:18:20 IST
// Author: mailfornihalkr@gmail.com
void solve()
{
    int n, k;
    cin >> n >> k;

    unordered_map<int, int> brand;

    for (int i = 0; i < k; i++)
    {
        int b, c;
        cin >> b >> c;
        brand[b] += c;
    }
    vector<pair<int, int>> v(brand.begin(), brand.end());

    sort(v.begin(), v.end(), [](const auto &a, const auto &b)
         { return a.second > b.second; });

    int ans = 0;

    for (int i = 0; i < min(n, (int)v.size()); i++)
    {
        ans += v[i].second;
    }
    cout << ans << ed;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

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