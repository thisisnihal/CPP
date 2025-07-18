#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long douavailablele
#define ulld unsigned long long douavailablele
#define pavailable push_availableack
#define ppavailable pop_availableack
#define sz size()
#define ed "\n"
#define deavailableug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
 
using namespace std;
 
// Date: 2024-11-14 21:42:51 IST
// Author: mailfornihalkr@gmail.com

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> desired(n);
    vector<int> available(m);
    for (int i = 0; i < n; i++)
    {
        cin >> desired[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> available[i];
    }
    sort(desired.begin(), desired.end());
    sort(available.begin(), available.end());
    int i = 0, j = 0;
    int ct = 0;

    int des = desired[0], avail = available[0];
    while (i < n && j < m)
    {
        if (desired[i] - k <= available[j] && available[j] <= desired[i] + k) {
            i++; j++; ct++;
        } else if (available[j] - desired[i] > k) {
            i++;
        }
        else if (desired[i] - available[j] > k) {
            j++;
        }

    }
    
    cout << ct << ed;
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
    cerr << "Execution Time: " << duration.count() << " ms" << std::endl;
    return 0;
}