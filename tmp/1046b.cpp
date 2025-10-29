#include <iostream>
#include <vector>
using namespace std;

int min_subset_size(vector<int> &arr) {
    int total_or = 0;
    for (int x : arr) total_or |= x;

    int ans = arr.size();
    for (int i = 0; i < arr.size(); ++i) {
        int or_exclude = 0;
        for (int j = 0; j < arr.size(); ++j) {
            if (i != j)
                or_exclude |= arr[j];
        }
        if (or_exclude != total_or)
            ans = 1;
    }
    if (ans == 1)
        return 1;

    int best = arr.size();
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr.size(); ++j) {
            if (i != j && (arr[i] | arr[j]) == total_or)
                best = min(best, 2);
        }
    }
    return best;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; ++i) cin >> arr[i];
        cout << min_subset_size(arr) << endl;
    }
}
