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
 
// Date: 2024-11-23 21:13:19 IST
// Author: mailfornihalkr@gmail.com
void solve()
{
    int n;
    unsigned long long k;
    cin >> n >> k;
    vector<unsigned long long> ans;
    unsigned long long X = ~0ULL;
    for (int i = 0; i < n; i++)
    {
        unsigned long long temp;
        cin >> temp;
        if ((temp & k) == k) {
            ans.push_back(i+1);
        }
    }

    if (ans.size() == 0) {
        cout << "NO" << endl;
    } else {
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        
    }

    


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
    cerr << "Execution Time: " << duration.count() << " ms" << std::endl;
    return 0;
}