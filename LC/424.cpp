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

int characterReplacement(string s, int k)
{
    int head, tail, maxlen = 0, most_frequent = 0;
    unordered_map<char, int> freq;
    for (head = 0, tail = 0; head < s.size(); head++)
    {
        freq[s[head]]++;
        most_frequent = max(most_frequent, freq[s[head]]); // count of most frequent element
        int window_size = head - tail + 1;                 // current window size
        if (window_size - most_frequent > k)
        { // if the current window size is still greater than k even after subtracting the count of most frequent element then remove one element from tail
            freq[s[tail]]--;
            if (freq[s[tail]] == 0)
                freq.erase(s[tail]);
            tail++;
        }
        maxlen = head - tail + 1; // updated window size
    }
    return maxlen;
}

int main()
{
    string s = "AABABBA";
    int k = 1;
    int ans = characterReplacement(s, k);
    cout << ans << endl;
    return 0;
}