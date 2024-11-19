#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2023-12-29 15:37:31 */
using namespace std;

bool isvowel(char c)
{
    return c == 'a' || c == 'e';
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string temp = "";
    for (int i = n - 1; i >= 0;)
    {
        if (i - 1 >= 0 and isvowel(s[i]) and !isvowel(s[i - 1]))
        {
            char ch[4] = {s[i], s[i - 1], '.', '\0'};
            temp.append(ch);
            i -= 2;
        }
        else if (i - 2 >= 0 and !isvowel(s[i]) and isvowel(s[i - 1]) and !isvowel(s[i - 2]))
        {
            char ch[5] = {s[i], s[i - 1], s[i - 2], '.', '\0'};
            temp.append(ch);
            i -= 3;
        }
        else
        {
            i--;
        }
    }
    if (temp[temp.size() - 1] == '.')
        temp.pop_back();

    reverse(temp.begin(), temp.end());
    cout << temp << ed;
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
