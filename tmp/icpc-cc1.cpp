#include <bits/stdc++.h>
using namespace std;
 
// Date: 2024-11-23 21:13:19 IST
// Author: mailfornihalkr@gmail.com
void solve()
{
    int n;
    unsigned long long k;
    cin >> n >> k;
    vector<unsigned long long> a(n);
    vector<int> indices;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if ((a[i] & k) == k) {
            indices.push_back(i + 1);
        }
    }

    if (indices.empty()) {
        cout << "NO" << endl;
        return;
    }

    unsigned long long m = indices.size();
    for (unsigned long long mask = 1; mask < (1 << m); mask++) {
        vector<int> subset;
        unsigned long long subsetAnd = ~0ULL; 
        for (unsigned long long j = 0; j < m; j++) {
            if (mask & (1 << j)) {
                int idx = indices[j] - 1; 
                subsetAnd &= a[idx];
                subset.push_back(indices[j]);
            }
        }

        if (subsetAnd == k) {
            cout << "YES" << endl;
            cout << subset.size() << endl;
            for (int idx : subset) {
                cout << idx << " ";
            }
            cout << endl;
            return;
        }
    }

    cout << "NO" << endl;
}
 
int main()
{
// ios::sync_with_stdio(false);
// cin.tie(NULL);
// auto start = chrono::high_resolution_clock::now();
 
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    // auto end = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    // cerr << "Execution Time: " << duration.count() << " ms" << std::endl;
    return 0;
}