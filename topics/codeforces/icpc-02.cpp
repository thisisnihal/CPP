#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int sum = 0;
    int count_gt_k = 0;
    int min_gt_k = INT_MAX;

    // Reading input and calculating sum
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        if (a[i] > k) {
            count_gt_k++;
            min_gt_k = min(min_gt_k, a[i]);
        }
    }

    // If no element is greater than k, no operation is possible
    if (count_gt_k < 2) {
        cout << sum << endl;
        return;
    }

    // Maximum number of operations we can perform
    int max_operations = min(count_gt_k / 2, min_gt_k - k);
    
    // Result after performing max_operations
    int result = sum - 2 * max_operations;
    
    cout << result << endl;
}

int main() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
