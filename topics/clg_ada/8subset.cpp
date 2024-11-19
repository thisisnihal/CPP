#include <iostream>
#include <vector>

using namespace std;

// Function to find a subset with the given sum using backtracking
bool findSubset(const vector<int>& arr, int sum, vector<int>& subset, int index) {
    if (sum == 0) { 
        for (int num : subset) cout << num << " "; 
        cout << endl; 
        return true; 
    }
    if (sum < 0 || index >= arr.size()) return false;

    // Include the current element
    subset.push_back(arr[index]);
    if (findSubset(arr, sum - arr[index], subset, index + 1)) return true;

    // Exclude the current element
    subset.pop_back();
    return findSubset(arr, sum, subset, index + 1);
}

int main() {
    int n, sum;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int& num : arr) cin >> num;
    
    cout << "Enter the desired sum: ";
    cin >> sum;

    vector<int> subset;
    if (!findSubset(arr, sum, subset, 0)) cout << "No subset with the given sum found." << endl;

    return 0;
}
