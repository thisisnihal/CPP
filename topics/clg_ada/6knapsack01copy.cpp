#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> wt, val;
vector<vector<ll>> dp;

ll knapsack(int idx, int wt_left) {
    if (wt_left == 0 || idx < 0) return 0;
    if (dp[idx][wt_left] != -1) return dp[idx][wt_left];

    // Do not choose the item at idx
    ll ans = knapsack(idx - 1, wt_left);
    if (wt_left - wt[idx] >= 0)
        ans = max(ans, knapsack(idx - 1, wt_left - wt[idx]) + val[idx]); // Choose the item at idx

    return dp[idx][wt_left] = ans;
}

int main() {
    int n = 3, w = 50;

    wt.resize(n);
    val.resize(n);
    dp.assign(n, vector<ll>(w + 1, -1)); // Initialize dp table

    wt = {10, 20, 30};
    val = {60, 100, 120};

    cout << knapsack(n - 1, w) << endl;
    return 0;
}
