#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-12-30 21:35:23 */
using namespace std;



void solve()
{
    set<int> v = {1, 7, 17, 119, 289, 2023};
    vector<int> ans;
    int n, k;
    unordered_set<int> setb;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (v.find(temp) != v.end()) {
            setb.insert(temp);
            v.erase(temp);
        } 
    }
 
    
    if (k == 1) {
        if (setb.find(2023) != setb.end()) cout << "YES" << ed;
        else cout << "NO" << ed;
        return;
    }


    
    
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >>t;
    while(t--)solve();
    return 0;
}

