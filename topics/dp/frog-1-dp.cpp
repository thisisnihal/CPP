#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-05-27 12:03:31 */
using namespace std;

const int N = 1e5+10;

int h[N];

// DEBUG and Observe
int func(int i, int dp[]) {
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];
    int cost = INT_MAX; 
    cost = min(cost, func(i-1, dp) + abs(h[i] - h[i-1]));
    if (i > 1) 
        cost = min(cost, func(i-2, dp) + abs(h[i] - h[i-2]));
    return dp[i] = cost;
}


// it also does the work
int func2(int i, int dp[]) {
    if (i == 0) return 0;
    if (i == 1) return dp[i] = abs(h[0]-h[1]);
    // if (i == 2) return dp[i] = min(abs(h[2]-h[1]), abs(h[2]-h[0]));  // this line is not required!!. infact it will make it wrong!
    if (dp[i] != -1) return dp[i];

    return dp[i] = min(func(i-1, dp) + abs(h[i] - h[i-1]), func(i-2, dp) + abs(h[i] - h[i-2]));
}

int func3(int n, int dp[]) {

    dp[0] = 0;
    dp[1] = abs(h[1]-h[0]);
    for (int i = 2; i < n ; i++) 
    {
        dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));
    }
    
    return dp[n-1];
}

int main()
{

    int n;
    cin >> n;
    int dp[n];
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    // n-1 cause its a 0th based indexing
    cout << func(n-1, dp) << ed;

    //  
    cout << func2(n-1, dp) << ed;

    // iterative method
    cout << func3(n, dp) << ed;
    
    return 0;
}