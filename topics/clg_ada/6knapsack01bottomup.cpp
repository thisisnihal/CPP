#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

ll knapsack(const vector<ll> &weights, const vector<ll> &values, int W)
{
    int N = weights.size();
    vector<vector<ll>> DP(N + 1, vector<ll>(W + 1, 0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j <= W; ++j)
        {
            if (weights[i] <= j)
            {
                DP[i + 1][j] = max(DP[i][j], values[i] + DP[i][j - weights[i]]);
            }
            else
            {
                DP[i + 1][j] = DP[i][j];
            }
        }
    }

    return DP[N][W];
}

int main()
{
    int n, W;
    n = 3, W = 50;

    vector<ll> weights(n), values(n);
    weights = {10, 20, 30};
    values = {60, 100, 120};

    cout << knapsack(weights, values, W) << endl;
    return 0;
}
