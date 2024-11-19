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
    string s, t;
    cin >> s >> t;
    int ct = 0;
    int s1 = s.sz, t1 = t.sz;
    for (int i = 0, j = 0; i < s1 && j < t1; i++, j++)
    {
        if (s[i] == t[j])
            ct++;
        else
            break;
    }
    s1 -= ct;
    t1 -= ct;
    if (ct) ct++;
    cout << s1 + t1 + ct << ed;
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