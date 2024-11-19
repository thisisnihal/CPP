#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-10-30 00:58:09 */
using namespace std;


int dp[205][205];
int f(int i, int j, vector<vector<int>>& A) {
    int n = A.size();
    int m = A[i].size();
    if (i == n-1) return 0;
    if (j >= m) return 1e5+10;
    if (dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = min(A[i][j]+f(i+1, j, A), A[i][j]+f(i+1, j+1, A));
}
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    memset(dp, -1, sizeof(dp));
    int mn = INT_MAX;
    for (int j = 0; j < triangle[n-1].size(); j++) mn = min(mn, triangle[n-1][j]);

    return mn + f(0, 0, triangle);
}

int main()
{
    
    return 0;
}