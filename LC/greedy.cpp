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


/**
 * 
 * 
 *  START
 */

// https://leetcode.com/problems/maximum-subarray/description/
int maxSubArray(vector<int>& nums) {
    int mx = INT_MIN, sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (mx < sum) {
            mx = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }
    return mx;
}



// https://leetcode.com/problems/jump-game/
bool canJump(vector<int>& nums) {
    int len = nums.size();
    int mxreach = 0;
    for (int i= 0; i < len; i++) {
        if (i > mxreach) return false;
        mxreach = max(i + nums[i], mxreach);
        if (mxreach >= len - 1) return true;
    }
    return true;
}

// https://leetcode.com/problems/jump-game-ii/description/
int jump(vector<int>& nums) {
    int len = nums.size();
    int mxreach = 0;
    int jumps = 0, end = 0;
    for (int i = 0; i < len - 1; i++) {
        mxreach = max(i + nums[i], mxreach);
        if (i == end) {
            jumps++;
            end = mxreach;
        }
    }
    return jumps;
}


// https://leetcode.com/problems/gas-station/description/
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, tank =0, start = 0;

        for (int i = 0; i < gas.size(); i++) {
            int gain = gas[i] - cost[i];
            total += gain;
            tank += gain;
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        return (total >= 0) ? start : -1;
        // sum(gas) >= sum(cost)
        // If this gain is:
        // Positive → you get more gas than you spend.
        // Negative → you lose gas overall.
    }


// https://leetcode.com/problems/hand-of-straights/description/
bool isNStraightHand(vector<int>& hand, int groupSize) {

    if (hand.size() % groupSize != 0) return false;

    map<int, int> mp;
    for (int card : hand) mp[card]++;

    for (auto& [card, freq] : mp) {
        if (freq > 0) {
            for (int next = 1; next < groupSize; next++) {
                if (mp[card + next] < freq)
                    return false; // not enough cards to form group
                mp[card + next] -= freq; // sub to form group
            }
        }
    }
    return true;
    // Whatever the frequency (freq) of the current card is, 
    // it means we need to start that many groups using this card — 
    // so we must consume (subtract) that same number of cards from all the next consecutive values in the sequence.
}


// https://leetcode.com/problems/merge-triplets-to-form-target-triplet/description/
bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    
    int x = target[0], y = target[1], z = target[2];
    bool a = 0, b = 0, c = 0;

    for (auto& t : triplets) {
        if (t[0] <= x && t[1] <= y && t[2] <= z) {
            if (t[0] == x) a = true;
            if (t[1] == y) b = true;
            if (t[2] == z) c = true;
        }
    }
    return a & b & c;
}


// https://leetcode.com/problems/partition-labels/description/
vector<int> partitionLabels(string s) {
    vector<int> last(26, 0);
    for (int i = 0; i < s.size(); i++) last[s[i] - 'a'] = i;

    vector<int> result;
    int start = 0, end = 0;

    for (int i = 0; i < s.size(); i++) {
        end = max(end, last[s[i] - 'a']);
        if (i == end) {
            result.push_back(end - start + 1);
            start = i + 1;
        }
    }
    return result;
// hume string ko aise parts me todna hai ki
// har char sirf ek hi part me aaye.
// koi letter dusre part me repeat na ho.
}



// https://leetcode.com/problems/valid-parenthesis-string/description/
bool checkValidString(string s) {
    stack<int> open, star;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            open.push(i);
        else if (s[i] == '*')
            star.push(i);
        else { // ')'
            if (!open.empty())
                open.pop();
            else if (!star.empty())
                star.pop();
            else
                return false;
        }
    }

    // match remaining '(' with later '*'
    while (!open.empty() && !star.empty()) {
        if (open.top() > star.top())
            return false; // '*' came before '(' -> invalid
        open.pop();
        star.pop();
    }

    return open.empty();
} // -------------------------
// USING GREEDY
bool checkValidString2(string s) {
    int low = 0, high = 0;
    for (char c : s) {
        if (c == '(') {
            low++;
            high++;
        } else if (c == ')') {
            low--;
            high--;
        } else { // '*'
            low--;
            high++;
        }

        if (high < 0)
            return false; // too many ')'
        if (low < 0)
            low = 0; // '*' can balance extra ')'
    }
    return low == 0;
}





int main() {
    // auto result = method();
    // cout << result << endl;
    // printArray(result);
    // print2DArray(result);
    return 0;
}




/**
 *  END
 */
































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