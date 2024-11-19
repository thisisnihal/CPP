#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2024-04-16 01:32:56 */
using namespace std;

int myAtoi(string s)
{

    long long ans = 0;
    smatch match;
    regex number_regex("\\b-?\\d+\\b");
    bool neg = false;
    if (regex_search(s, match, number_regex))
    {
        string num_str = match.str();
        neg = num_str[0] == '-';
        int i = neg ? 1 : 0;
        for (int i = neg ? 1 : 0; i < num_str.size(); i++)
        {
            ans = ans * 10 + (num_str[i] - '0');

            if (neg && temp_ans > (1L << 31))
                return -1L * (1L << 31);
        }
        if (!neg && temp_ans > (1 << 30))
            return (1 << 31 - 1);
    }
    return (neg ? -1 * ans : ans);
}

int main()
{

    return 0;
}