#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2024-04-08 20:36:51 */
using namespace std;

void solve()
{
    int n, c, d;
    cin >> n >> c >> d;
    multiset<int> st;
    int mn = INT_MAX;

    for (int i = 0; i < n * n; i++)
    {
        int temp;
        cin >> temp;
        mn = min(mn, temp);
        st.insert(temp);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ll cur = mn + (i * c) + (j * d);
            auto it = st.find(cur);
            if (it == st.end()) {
                cout << "NO" << ed;
                return;
            }
            st.erase(it);
        }
    }

    cout << "YES" << ed;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s = "[[2,1],[1,0],[1,4],[1,8],[3,5],[4,6]]";
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '[') s[i] = '{';
        else if (s[i] == ']') s[i] = '}';
    }
    cout << s ;
//     int t = 1;
//     cin >> t;
//     while (t--)
//         solve();
    return 0;
}
