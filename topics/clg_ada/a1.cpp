#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define sz size()
#define ed "\n"

using namespace std;

void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    int k;
    bool flag = 0;
    while (true)
    {
        if (a + 1 == b)
        {
            if (b + 1 == d)
            {
                flag = 1;
                break;
            }
            b++;
        }
        else
        {
            if (a + 1 == c)
            {
                flag = 1;
                break;
            }
            a++;
        }
        if (a == b)
        {
            flag = 1;
            break;
        }
        if (a == c && b == d)
            break;
    }
    if (flag)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
