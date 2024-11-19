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

bool consistOf3s6s(ull num)
{
    while (num > 0)
    {
        ull digit = num % 10;
        if (digit != 6 && digit != 3)
            return false;
        num /= 10;
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;
    int d = n - 1;
    for (int ct3 = 0; ct3 <= d; ++ct3)
    {
        int ct6 = d - ct3;

        int odd = (ct3 + ct6 / 2) * 3 + (ct6 / 2) * 6;
        int even = (ct6 - ct6 / 2) * 6;

        odd += 6;

        if ((odd - even) % 11 == 0)
        {
            for (int i = 0; i < ct3; ++i)
                cout << "3";
            for (int i = 0; i < ct6; ++i)
                cout << "6";
            cout << ed;
            return;

        }
    }
    cout << -1 << ed;
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