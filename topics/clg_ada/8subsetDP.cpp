#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> dp;

bool findSubset(int index, int sum, const vector<int>& arr) {
    if (sum == 0) return true;
    if (index < 0) return false;
    if (dp[index][sum] != -1) return dp[index][sum];
    if (arr[index] > sum) return dp[index][sum] = findSubset(index - 1, sum, arr);
    return dp[index][sum] = findSubset(index - 1, sum, arr) || findSubset(index - 1, sum - arr[index], arr);
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = arr.size();
    
    dp.assign(n, vector<bool>(sum + 1, -1));

    if (findSubset(n - 1, sum, arr)) {
        cout << "Subset with the given sum found." << endl;
    } else {
        cout << "No subset with the given sum exists." << endl;
    }

    return 0;
}
