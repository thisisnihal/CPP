#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2023-05-10 22:40:39 */
using namespace std;
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    return ((n * n + n) / 2 - accumulate(nums.begin(), nums.end(), 0));
}
int gcd(int r1, int r2)
{
    while (true)
    {
        int r3 = r2 % r1;
        if (r3 == 0)
            return r1;
        r2 = r1;
        r1 = r3;
    }
    return r2;
}

int func_gcd(int a, int b) {
    if (b == 0) return a;
    return func_gcd(b, a%b);
}

int main()
{
    cout << func_gcd(12, 68) << ed;
    cout << gcd(12, 68) << ed;
    return 0;
}