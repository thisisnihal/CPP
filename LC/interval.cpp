#include <bits/stdc++.h>
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




// ---------------------------
// https://leetcode.com/problems/insert-interval/description/
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;

    for (auto& it : intervals) {
        if (res.empty() || res.back()[1] < it[0]) {
            res.push_back(it);
        } else {
            res.back()[1] = max(res.back()[1], it[1]);
        }
    }
    return res;
}
// OR
vector<vector<int>> merge2(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;
    int start = intervals[0][0], end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {
        int currStart = intervals[i][0], currEnd = intervals[i][1];

        if (currStart <= end) { 
            end = max(end, currEnd);
        } else {
            ans.push_back({start, end});
            start = currStart;
            end = currEnd;
        }
    }
    ans.push_back({start, end});
    return ans;
} 
// ---------------------------


// ---------------------------
// https://leetcode.com/problems/insert-interval/description/
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

    intervals.push_back(newInterval); 
    
    auto ans = merge2(intervals);
   

    return ans;
}
// OR
vector<vector<int>> insert2(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    int i = 0, n = intervals.size();

    // step 1: add all before newInterval
    while (i < n && intervals[i][1] < newInterval[0])
        res.push_back(intervals[i++]);

    // step 2: merge overlapping
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push_back(newInterval);

    // step 3: add remaining
    while (i < n) res.push_back(intervals[i++]);

    return res;
}
//-----------------------------------



// https://leetcode.com/problems/non-overlapping-intervals/description/
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
            [](auto& a, auto& b) { return a[1] < b[1]; });
    
    int cnt = 0, end = INT_MIN;

    for (auto& it : intervals) {

        if (it[0] < end) cnt++; // overlap -> remove one

        else end = it[1]; // move to next valid
    }
    return cnt;

    // sort by end time 
    // always pick interval with smallest end.
    // if next starts before previous ends -> overlap -> increment count.

    // [[1,2],[2,3],[3,4],[1,3]]
    // sort by end → [[1,2],[1,3],[2,3],[3,4]]
    // pick [1,2], next [1,3] overlaps → remove++
    // end = 2, then [2,3] ok, [3,4] ok
    
}


// https://neetcode.io/problems/meeting-schedule?list=neetcode150
bool canAttendMeetings(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < intervals[i-1][1])
            return false;
    }
    return true;

// Sort by start time.
// If any meeting starts before previous one ends → conflict.
// [[0,30],[5,10],[15,20]]
// → sorted same
// [5,10] starts before 30 ends → X
}












int main() {
    // auto result = method();
    // cout << result << endl;
    // printArray(result);
    // print2DArray(result);
    return 0;
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
template <typename T>
void printDeque(const deque<T>& dq) {
    cout << "Deque (front -> back): [";
    for (size_t i = 0; i < dq.size(); ++i) {
        cout << dq[i];
        if (i != dq.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}