#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2024-04-08 20:36:51 */
using namespace std;

void solve()
{
    int n, c, d;
    cin >> n >> c >> d;
    unordered_multiset<int> st;
    int mn = INT_MAX;

    for (int i = 0; i < n * n; i++)
    {
        int temp;
        cin >> temp;
        mn = min(mn, temp);
        st.insert(temp);
    }
    // cout << "min = " << mn << ed;
    // int a[n+1][n+1];
    // a[1][1] = mn;
    bool flag = true;
    int ai1j = mn;
    for (int i = 1; i <= n; i++)
    {
        int aij1 = ai1j;
        for (int j = 1; j <= n; j++)
        {
            if (st.find(aij1) == st.end()) {
                flag = false;
                break;
            } else {
                auto it = st.find(aij1);
                st.erase(it);
            }
            // cout << aij1 << " ";
            aij1 += d;
        }
        // cout << ed;
        if (!flag) break;
        ai1j += c;
    }
    
    if (flag) cout << "YES" << ed;
    else cout << "NO" << ed;

    
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}

