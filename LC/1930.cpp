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















// P₃(s) = Union of {s[i] + s[j] + s[k]} for all valid indices i, j, k such that:
// 1.  i < j < k 
// 2. s[i] = s[k]


class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ct = 0;
        int n = s.size();
        unordered_set<string> st;
        for (int i = 0; i < n; i++)
        {
            for (int k = i+2; k < n; k++)
            {
                if (s[i] == s[k]) {
                    for (int j = i+1; j < k; j++)
                    {
                        string temp = string(1, s[i]) + string(1, s[j]) + string(1, s[k]);
                        if (st.find(temp) == st.end()) {
                            st.insert(temp);
                            ct++;
                            cout << temp << endl;
                        }
                    }
                    
                }
            }
        }
        

        return ct++;
    }
};
 
int main()
{

    Solution solution;


    // vector<int> 
    // vector<vector<int> 
    string s = "aabca";
    // char c
    // int k
    // double d
    // float f



    auto result = solution.countPalindromicSubsequence(s);


    cout << result << endl;

    // printArray(result);

    // print2DArray(result);



}



























template <typename T>
void printArray(const vector<T>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}
template <typename T>
void print2DArray(const vector<vector<T>>& arr) {
    cout << "[" << endl;
    for (const auto& row : arr) {
        cout << "  [";
        for (size_t i = 0; i < row.size(); ++i) {
            cout << row[i];
            if (i != row.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

template <typename T>
void printSet(const set<T>& s) {
    cout << "{";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it;
        if (next(it) != s.end()) cout << ", ";
    }
    cout << "}" << endl;
}

template <typename T>
void printUnorderedSet(const unordered_set<T>& s) {
    cout << "{";
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it;
        if (next(it) != s.end()) cout << ", ";
    }
    cout << "}" << endl;
}

template <typename K, typename V>
void printMap(const map<K, V>& m) {
    cout << "{";
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << ": " << it->second;
        if (next(it) != m.end()) cout << ", ";
    }
    cout << "}" << endl;
}

template <typename K, typename V>
void printUnorderedMap(const unordered_map<K, V>& m) {
    cout << "{";
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << ": " << it->second;
        if (next(it) != m.end()) cout << ", ";
    }
    cout << "}" << endl;
}
template<typename K, typename V>
void printPair(const pair<K, V>& p) {
    cout << "{" << p.first << ", " << p.second <<"}" << endl;
}


