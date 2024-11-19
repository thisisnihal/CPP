#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2023-10-30 13:26:25 */
using namespace std;





int dp[500][500];
int f(int i, int j, int m, int n) {
    if (i == m-1 && j == n-1) return 1;
    if (i >= m || j >= n) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = f(i+1, j, m, n) + f(i, j+1, m, n);
}

// Method 2
int uniquePaths_2(int m, int n) {
    memset(dp, -1, sizeof(dp));
    return f(0, 0, m, n);
}

// Method 3
int uniquePaths_3(int m, int n) {
    unsigned long long N = 1, D = 1;
    for (int i = max(m, n); i <= m+n-2; i++, D++) N = (i*1ULL*N)/D;
    
    // for (int i = 1; i < min(m, n); i++) D = i*1ULL*D;
    
    return N;
}


int M = 1e9+7;
int F[500];
// Method 1 but incorrect actually have to do modular division
int uniquePaths(int m, int n)
{
    cout << F[m + n - 2] << " " << F[m-1] << " " << F[n-1] << ed;
    return  F[m + n - 2] / ((F[m-1] *1LL * F[n-1] ));
}

int main()
{

    F[0] = 1, F[1] = 1;
    for (int i = 2; i < 480; i++)
    {
        F[i] = (i *1LL* F[i - 1]) % M;
    }
    int m, n;
    cin >> m >> n;
    unsigned ll ans = uniquePaths(m, n);
    
    cout << "ans = " << ans << ed;
    return 0;
}