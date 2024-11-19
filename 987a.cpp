#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define ulld unsigned long long double
#define pb push_back
#define ppb pop_back
#define sz size()
#define ed "\n"

using namespace std;
 
// Date: 2024-11-15 18:17:27 IST
// Author: mailfornihalkr@gmail.com
void solve()
{
    int n;
    cin >> n;
    vector<int> h(n+1, 0);
    int mxct = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        h[x]++;
        mxct = max(mxct, h[x]);
    }
    cout <<(n - mxct) << ed;
    
    
}
 
int main()
{
ios::sync_with_stdio(false);
cin.tie(NULL);
auto start = chrono::high_resolution_clock::now();
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // cerr << "Execution Time: " << duration.count() << " ms" << std::endl;
    return 0;
}