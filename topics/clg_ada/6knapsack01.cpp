#include <bits/stdc++.h>
using namespace std;

vector<int> wt, val;
vector<vector<long long>> dp;

long long knapsack(int idx, int wt_left) {
    if (wt_left == 0 || idx < 0) return 0;
    if (dp[idx][wt_left] != -1) return dp[idx][wt_left];

    // Do not choose the item at idx
    long long ans = knapsack(idx - 1, wt_left);
    if (wt_left - wt[idx] >= 0)
        ans = max(ans, knapsack(idx - 1, wt_left - wt[idx]) + val[idx]); // Choose the item at idx

    return dp[idx][wt_left] = ans;
}

int main() {
    int n, w;
    cin >> n >> w;

    wt.resize(n);
    val.resize(n);
    dp.assign(n, vector<long long>(w + 1, -1)); // Initialize dp table

    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }

    cout << knapsack(n - 1, w) << endl;
    return 0;
}
