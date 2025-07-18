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




const int M = 1e9 + 7;
const int X = 1e5 + 1;

vector<vector<unsigned int>> C(X, vector<unsigned int>(X, 0));

void precompute() {
    for (int n = 0; n < X; n++) {
        C[n][0] = 1; // First element in each row is 1
        C[n][n] = 1; // Last element in each row is 1
        if (n == 0) continue; // Skip the first row
        for (int k = 1; k < n; k++) {
            C[n][k] = C[n][k - 1] + C[n - 1][k - 1];
            C[n][k] %= M; // Apply modulo operation to avoid overflow
        }
    }
}

void solve() {
    precompute();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << C[n][k] << endl;
    }
}



int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}