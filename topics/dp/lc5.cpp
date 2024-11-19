#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2023-10-31 19:45:41 */
using namespace std;

pair<int, int> dp[1000][1000];
bool isPalindrome(int i, int j, string &s)
{
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        i++, j--;
    }
    return true;
}
int mxlen = 0;
pair<int, int> max(pair<int, int> pr1, pair<int, int> pr2)
{
    int l1 = pr1.second - pr1.first + 1;
    int l2 = pr2.second - pr2.first + 1;
    int temp = l1 <= l2 ? l2 : l1;
    mxlen = __max(mxlen, temp);
    return l1 <= l2 ? pr2 : pr1;
}

pair<int, int> f(int i, int j, string &s)
{
    if (i >= s.size() || j >= s.size())
        return {INT_MIN, INT_MIN};
    if (isPalindrome(i, j, s))
        return {i, j};
    if (dp[i][j].first != -1 and dp[i][j].second != -1)
        return dp[i][j];

    return dp[i][j] = max(f(i + 1, j + 1, s), f(i, j + 1, s));
}
string longestPalindrome(string s)
{
    string ans = "";

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            dp[i][j] = make_pair(-1, -1);
        }
    }
    pair<int, int> pr = f(0, 1, s);
    // for (int i = 0; i < 1000; i++)
    // {
    //     for (int j = 0; j < 1000; j++)
    //     {
    //         dp[i][j] = make_pair(-1, -1);
    //     }
    // }
    // pr = max(pr, f(0, 2, s));
    for (int i = pr.first; i <= pr.second; i++)
    {
        ans.push_back(s[i]);
    }

    return ans;
}
int main()
{

    string s = "babad";
    cin >> s;
    int n = s.size();

    string res = longestPalindrome(s);
    cout << res << ed;
    return 0;
}