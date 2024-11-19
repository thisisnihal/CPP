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
 
// Date: 2024-11-16 18:03:12 IST
// Author: mailfornihalkr@gmail.com
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n), pf(n);
    
   for(auto&it:v) cin >> it;

   sort(v.begin(), v.end());

    pf[0] = v[0];

    for (auto&it:v) cout << it << " ";
    cout << ed;
    // for(int i = 1; i < n; i++) pf[i] = v[i] + pf[i-1];

    for (int i =1; i < n; i++)
    {
        int m = i + 1;
        if (m > k) {
            v[i] = v[i] + v[i-1] - v[i-k];
        } else {
            v[i] += v[i-1];
        }

    }
    
    for (auto&it:v) cout << it << " ";
    
    cout << endl;

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