#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define ulld unsigned long long double
using namespace std;
template <typename T>
void printArray(const vector<T> &arr);
template <typename T>
void print2DArray(const vector<vector<T>> &arr);
template <typename T>
void printSet(const set<T> &s);
template <typename T>
void printUnorderedSet(const unordered_set<T> &s);
template <typename K, typename V>
void printMap(const map<K, V> &m);
template <typename K, typename V>
void printUnorderedMap(const unordered_map<K, V> &m);
template <typename K, typename V>
void printPair(const pair<K, V> &p);




















class Solution
{
public:
    vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
    {
        int n = nums.size();
        vector<int> ans(n);
        int mx  = (1 << maximumBit) - 1;
        ans[n-1] = nums[0] ^ mx;
        for (int i = 1; i < n; i++)
        {
            nums[i] ^= nums[i-1];
            ans[n-i - 1] = nums[i] ^ mx;
        }

        // printArray(nums);
        return ans;
    }
};

int main()
{

    Solution solution;

    vector<int> nums = {0,1,1,3};
    // vector<vector<int>>
    // string s
    // char c
    int k = 2;
    // double d
    // float f

    auto result = solution.getMaximumXor(nums, k);

    // cout << result << endl;

    printArray(result);

    // print2DArray(result);
}




























template <typename T>
void printArray(const vector<T> &arr)
{
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i)
    {
        cout << arr[i];
        if (i != arr.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}
template <typename T>
void print2DArray(const vector<vector<T>> &arr)
{
    cout << "[" << endl;
    for (const auto &row : arr)
    {
        cout << "  [";
        for (size_t i = 0; i < row.size(); ++i)
        {
            cout << row[i];
            if (i != row.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

template <typename T>
void printSet(const set<T> &s)
{
    cout << "{";
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        cout << *it;
        if (next(it) != s.end())
            cout << ", ";
    }
    cout << "}" << endl;
}

template <typename T>
void printUnorderedSet(const unordered_set<T> &s)
{
    cout << "{";
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        cout << *it;
        if (next(it) != s.end())
            cout << ", ";
    }
    cout << "}" << endl;
}

template <typename K, typename V>
void printMap(const map<K, V> &m)
{
    cout << "{";
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << ": " << it->second;
        if (next(it) != m.end())
            cout << ", ";
    }
    cout << "}" << endl;
}

template <typename K, typename V>
void printUnorderedMap(const unordered_map<K, V> &m)
{
    cout << "{";
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << ": " << it->second;
        if (next(it) != m.end())
            cout << ", ";
    }
    cout << "}" << endl;
}
template <typename K, typename V>
void printPair(const pair<K, V> &p)
{
    cout << "{" << p.first << ", " << p.second << "}" << endl;
}