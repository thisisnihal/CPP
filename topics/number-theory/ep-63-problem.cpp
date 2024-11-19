#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-05-18 21:49:10 */
using namespace std;


// https://www.hackerearth.com/problem/algorithm/monk-and-divisor-conundrum-56e0eb99/

const int N = 2e5+10;
int hsh[N];
int multiple_cnt[N];

int main()
{
    int n;
    cin >> n;
    // storing count of each element.
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        hsh[x]++;
    }
    // storing count of multiples
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j+=i)
        {
            multiple_cnt[i] += hsh[j];
        }
    }

    // for q queries:
    int q;
    cin >> q;
    while (q--)
    {
        int p, q;
        cin >> p >> q;
        long long lcm = p * 1LL * q / __gcd(p,q);
        long long ans = multiple_cnt[p] + multiple_cnt[q];    
        if (lcm < N) ans -= multiple_cnt[lcm];
        cout << ans << endl;
    }
    return 0;
}