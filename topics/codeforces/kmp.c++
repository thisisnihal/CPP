#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2023-12-10 17:08:40 */
using namespace std;

vector<int> lps;

void calculatelps(string &pat)
{
    int M = pat.size();
    int j = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[j])
        {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void solve()
{
    string txt, pat;
    // cin >> txt >> pat;
    pat = "AAACAAAA";
    lps.resize(pat.size());
    calculatelps(pat);
    for (int e : lps)
        cout << e << " ";
}
/*
ABABABCABABABCABABABC
ABABAC
*/
int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int t = 1;
    // cin >>t;
    while (t--)
        solve();
    return 0;
}
