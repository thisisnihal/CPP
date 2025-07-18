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

template <typename T>
void printArray(const vector<T>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];
        auto it = mp.find(target - num);
        if ( it != mp.end())
        {
            return {i, mp[target - num]};
        }
        mp[num] = i;
    }
    return {-1, -1};
}

int main()
{
    vector<int> nums = {2,7,11,15};
    auto ans = twoSum(nums, 9);
    printArray(ans);
    return 0;
}