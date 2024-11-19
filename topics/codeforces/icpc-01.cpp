#include <bits/stdc++.h>
/* author: nihal136nihal@gmail.com
* created at 2024-11-10 14:33:55 */
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> moreThanK;
    int sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp > k) moreThanK.push_back(temp);
        else sum += temp;
    }
    sort(moreThanK.begin(), moreThanK.end());
    int sz = moreThanK.size();
    if (sz == 0) {
        cout << sum << endl;
        return;
    }
    for (size_t i = 0; i < sz-1; i++)
    {
        int mn = min(moreThanK[i], moreThanK[i+1]);
        int sub = mn - k;
        moreThanK[i] -= sub;
        moreThanK[i+1] -= sub;
        sum += moreThanK[i];
    }
    sum += moreThanK[sz-1];
    
    cout << sum << endl;
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