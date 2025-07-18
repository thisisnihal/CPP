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
 string bin(int n) {
        string s;
        while(n > 0) {
            int r = n % 2;
            s.push_back(r + '0');
            n /= 2;
        }
        reverse(s.begin(), s.end());
         return s;
        
    }
    int maxGoodNumber(vector<int>& nums) {
        int mx = 0;
        vector<string> s = {bin(nums[0]), bin(nums[1]), bin(nums[2])};
        
        vector<string> ct(3);
        
        for (int i = 0; i < 3; i++) {
            string temp = s[i] + s[(i+1)%3] + s[(i+2)%3];
            ct[i] = (temp);
        }
        sort(ct.begin(), ct.end());
        cout << bin(ct[2]) << endl;
        int x = stoi(bin(ct[2]));
        return x;
    }

void solve()
{
    vector<int> nums = {1,2,3};
    int ans = maxGoodNumber(nums);
    cout << "ans = " << ans << ed;
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