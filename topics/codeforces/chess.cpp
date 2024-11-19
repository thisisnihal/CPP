#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-12-12 14:34:33 */
using namespace std;

void solve()
{
    int a,b;
    int kx, ky, qx, qy;
    cin >> a >> b;
    cin >> kx >> ky;
    cin >> qx >> qy;

    set<pair<int,int>> set_k, set_q;
    for (int e : {0, 1}) {
        int x, y;
        if (e == 0) x = a, y = b;
        else x = b, y = a;

        set_k.insert({kx - x, ky - y});
        set_k.insert({kx - x, ky + y});
        set_k.insert({kx + x, ky - y});
        set_k.insert({kx + x, ky + y});

        set_q.insert({qx - x, qy - y});
        set_q.insert({qx - x, qy + y});
        set_q.insert({qx + x, qy - y});
        set_q.insert({qx + x, qy + y});
    }

    int ct = 0;
    for (auto e : set_q) {
        if (set_k.find(e) != set_k.end()) ct++;
    }
    cout << ct << ed;

    
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >>t;
    while(t--)solve();
    return 0;
}

