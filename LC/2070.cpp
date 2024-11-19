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







class Solution {
public:
 vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int,int> mp;
        for(auto& v : items) {
            mp[v[0]] = v[1];
        }
        printMap(mp);
        vector<int> res;
        for(int q : queries) {
            auto it = mp.lower_bound(q);
            if (abs(it->first) <= q && it != mp.end()) {
                cout << it->first << " " << it->second << endl;
                int a = it->second;
                res.push_back(a);
            } else {
                cout << 0 << endl;
                res.push_back(0);
            }
        }
        return res;
    }
};
 
int main()
{

    Solution solution;


    // vector<int> 
    // vector<vector<int> 
    // string s
    // char c
    // int k
    // double d
    // float f


    vector<vector<int>> items = {{193,732},{781,962},{864,954},{749,627},{136,746},{478,548},{640,908},{210,799},{567,715},{914,388},{487,853},{533,554},{247,919},{958,150},{193,523},{176,656},{395,469},{763,821},{542,946},{701,676}};
    vector<int> queries = {885,1445,1580,1309,205,1788,1214,1404,572,1170,989,265,153,151,1479,1180,875,276,1584};
    auto result = solution.maximumBeauty(items, queries);

    // cout << result << endl;

    printArray(result);

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