#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Function to calculate GCD
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Function to count coprime pairs
ll countCoprimePairs(vector<int>& arr) {
    int n = arr.size();
    ll count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(gcd(arr[i], arr[j]) == 1) {
                count++;
            }
        }
    }
    return count;
}

// Function to solve each test case
vector<int> solveTestCase(int N, ll K) {
    vector<int> result;
    
    // Calculate maximum possible pairs
    ll maxPairs = (1LL * N * (N - 1)) / 2;
    
    // Handle impossible cases
    if(K > maxPairs) {
        return {-1};
    }
    
    // Special cases
    if(N == 1) {
        if(K == 0) return {2};
        return {-1};
    }
    
    if(N == 2) {
        if(K == 1) return {2, 3};
        if(K == 0) return {2, 4};
        return {-1};
    }

    if(K == 0) {
        result.resize(N, 2);
        return result;
    }
    
    if(N == 3) {
        if(K == 2) return {2, 3, 4};
        if(K == 3) return {2, 3, 5};
        return {-1};
    }
    
    if(N == 4) {
        if(K == 3) return {2, 3, 4, 9};
        if(K == 4) return {2, 3, 5, 7};
        if(K == 5) return {2, 3, 5, 11};
        if(K == 6) return {2, 3, 7, 11};
        return {-1};
    }
    

    
    result.push_back(2);  
    
    ll remaining = K;
    int currentNum = 3;
    
    for(int i = 1; i < N; i++) {
        if(remaining <= 0) {
            result.push_back(result.back() * 2);
            continue;
        }
        
        while(currentNum <= 2000000) {  
            bool good = true;
            int coprimes = 0;
            
            for(int j = 0; j < result.size(); j++) {
                if(gcd(currentNum, result[j]) == 1) {
                    coprimes++;
                }
            }
            
            if(coprimes <= remaining) {
                result.push_back(currentNum);
                remaining -= coprimes;
                break;
            }
            currentNum++;
        }
        
        if(currentNum > 2000000) {
            return {-1}; 
        }
    }
    
    // Verify the solution
    if(countCoprimePairs(result) != K) {
        return {-1};
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    
    while(T--) {
        int N;
        ll K;
        cin >> N >> K;
        
        vector<int> result = solveTestCase(N, K);
        
        for(int i = 0; i < result.size(); i++) {
            cout << result[i];
            if(i < result.size() - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}