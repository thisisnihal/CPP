#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2024-04-08 21:07:47 */
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ct = 0;
    int i = 0, j = n - 1;
    for (int l = 1; l <= k; l++)
    {
        if (l % 2)
        {
            bool flag = 0;
            if (a[i])
            {
                a[i]--;
                flag = 1;
            }
            if (!a[i] && flag && i + 1 != j)
            {
                // ct++;
                i++;
            }
        }
        else
        {
            bool flag = 0;
            if (a[j])
            {
                a[j]--;
                flag = 1;
            }
            if (!a[j] && flag)
            {
                // ct++;
                j--;
            }
        }
    }
    for (int e : a){
        if (!e) ct++;
        // cout << e << " ";
    } 
    // cout << "\nans = ";

    cout << ct << ed;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
