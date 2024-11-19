#include <bits/stdc++.h>
/* author: nihal136nihal@gmail.com
* created at 2024-11-10 13:07:55 */
using namespace std;

void solve() {
    int n;
    cin >> n;
    unordered_map<string, pair<int,int>> mp;
    for (size_t i = 0; i < n; i++)
    {
        string w; int s;
        cin >> w >> s;
        if (s == 0) {
            mp[w].first += 1;
        } else {
            mp[w].second += 1;
        }
    }
    int ct = 0;
    for(auto& a : mp) {
        pair<int,int> pr = a.second;
        if (pr.first > pr.second) {
            ct += pr.first;
        } else {
            ct += pr.second;
        }
    }
    cout << ct << endl;
     
}

int main()
{
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}