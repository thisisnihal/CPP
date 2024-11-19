#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-11-03 23:25:14 */
using namespace std;


void print(vector<vector<int>>& v) {
   cout << "    ";
   for (int i = 0; i < v.size(); i++) cout << i << " ";
   cout << ed;
   for (int i = 0; i < v.size(); i++)
   {
        cout << i << "   ";
        for (int j = 0; j < v[0].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << ed;
        
   }
   
}

int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n-1; i >= 0; i--) {
        dp[i][i] = 1;
        for (int j = i+1; j < n; j++) {
            if (s[i] == s[j])
                dp[i][j] = dp[i+1][j-1] + 2;
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    print(dp);
    return dp[0][n-1];
}


int main()
{
    string s = "bbbab";
    int ans = longestPalindromeSubseq(s);
    cout << "\nans = " << ans << ed;
    return 0;
}