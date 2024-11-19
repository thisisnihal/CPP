#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2024-11-10 22:02:17 */
using namespace std;

void solve()
{
    int n, a, b, x = 0, y = 0;
    string s;
    cin >> n >> a >> b;
    cin >> s;
    if (a == 0 && b == 0) {
        cout << "YES\n";
        return;
    }
    for(char c : s) {
        if (c == 'N') {
            y++;
        } else if (c == 'S') {
            y--;
        } else if (c == 'E') {
            x++;
        } else {
            x--;
        }
    }
    cout << x << ", " << y << ed;
    if (a*y == b*x && b*x != 0) {
        cout << "YES" << ed;
    }else {
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
    cin >>t;
    while(t--)solve();
    return 0;
}

