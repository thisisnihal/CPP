#include <bits/stdc++.h>

using namespace std;
 
// Date: 2024-11-16 12:46:57 IST
// Author: mailfornihalkr@gmail.com
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> red(n), redV(n);
    vector<int> blue(m), blueV(m);
   for (size_t i = 0; i < n; i++)
   {
        cin >> red[i] >> redV[i];
   }
   
    for (size_t i = 0; i < m; i++)
    {
        cin >> blue[i] >> blueV[i];
    }
   unordered_set<int> setx, sety;
   int collision = 0;

   for (size_t i = 0; i < n; i++)
   {
        if (setx.find(i) != setx.end()) continue;
        for (size_t j = 0; j < m; j++)
        {
             if (sety.find(j) != sety.end()) continue;

             double_t tx = (double_t) blue[j] / blueV[j];
             double_t ty = (double_t) red[i] / redV[i];
             double diff =  abs(tx-ty);
             if (diff <= 1e-7) {
                setx.insert(i);
                sety.insert(j);
                collision++;
                break;
             }

        }
        
   }
   
    cout << collision << endl;


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
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}