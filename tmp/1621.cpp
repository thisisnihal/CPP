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
 
// Date: 2024-11-14 21:10:57 IST
// Author: mailfornihalkr@gmail.com
void solve()
{
    int n;
    cin >> n;
    vector<bool> v(1e9+10,0);
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (!v[x]) {
            v[x] = true;
            ct++;
        } 
    }
    cout << ct << ed;
    
}

void solve2() {
     int n;
    cin >> n;
    // unordered_set<int> st; // this set's ops takes O(n) in worst case
    set<int> st; // O(logn) in worst case , so use this
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    cout << st.size() << ed;

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
    //cin >> t;
    while (t--) {
        solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

    cerr << "Execution Time: " << duration.count() << " ms" << ed;
    return 0;
}