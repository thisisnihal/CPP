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

// Date: 2025-07-08 00:06:23 IST
// Author: mailfornihalkr@gmail.com
bool isPalindrome(string s)
{
    int n = s.size();
    int lo = 0, hi = n - 1;
    while (hi - lo >= 1)
    {
        while (!isalnum(s[lo]))
            lo++;
        while (!isalnum(s[hi]))
            hi--;

        cout << s[lo] << ":" << s[hi] << " - "<< lo  << ":" << hi << ed;
        if (tolower(s[lo]) != tolower(s[hi]))
            return false;
        else
            lo++, hi--;
    }
    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    cout << "ans = " <<  isPalindrome(s) << ed;
    return 0;
}