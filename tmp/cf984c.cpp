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

// Date: 2024-11-02 21:33:18 IST
// Author: mailfornihalkr@gmail.com
void solve()
{
    string s;
    char ch;
    unordered_set<int> st;
    while (cin.get(ch) && ch != '\n')
    {

        s.push_back(ch);
        int n = s.size();
        if (n >= 4)
        {
          if (s[n-4] == '1' &&  s[n-3] == '1' && s[n-2] == '0' && s[n-1] == '0') {
                st.insert(n-4);
          }
        }
    }
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int pos;
        char v;
        cin >> pos >> v;
        pos--;
        s[pos] = v;
        for (int j = pos; j < pos+4; j++)
        {
            int n = pos;
             if (s[n-4] == '1' &&  s[n-3] == '1' && s[n-2] == '0' && s[n-1] == '0') {
                st.insert(n-4);
          }
        }
        
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}