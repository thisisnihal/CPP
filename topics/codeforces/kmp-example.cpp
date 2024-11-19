#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2023-12-14 12:13:35 */
using namespace std;

void compute_lps(vector<int>& lps, string &pat) {
    int j = 0, i = 1;
    lps[0] = 0;
    while (i < pat.size()) 
    {
        if (pat[i] == pat[j]) 
        {
            lps[i] = j + 1;
            i++, j++;
        }
        else
        {
            if (j == 0)
            {
                lps[i] = 0;
                i++;
            } 
            else 
            {
                j = lps[j - 1];
            }
        }
    }
}
int strStr(string txt, string pat) {
    vector<int> lps(pat.size(), 0);
    compute_lps(lps, pat);
    int i = 0, j = 0;
    while (j < pat.size() && i < txt.size()) 
    {
        if (pat[j] == txt[i]) i++, j++;
        else {
            if (j == 0) i++;
            else j = lps[j-1];
        }
    }
    if (j == pat.size()) return i-j;
    else return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    string txt, pat;
    cin >> txt >> pat;
    int pos = strStr(txt, pat);
    if (pos == -1) cout << "Not found!" << ed;
    else cout << "found at " << pos << ed;
    return 0;
}