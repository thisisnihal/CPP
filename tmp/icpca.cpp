#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll MOD = 998244353;
 
ll pow_mod(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
 
ll solve(ll n) {
    ll res = 0, cur = 1, digits = 1;
    while (cur <= n) {
        ll end = min(n + 1, cur * 2);
        ll count = end - cur;
        
        ll first = pow_mod(10, digits * count - 1);
        ll mult = pow_mod(10, digits);
        ll sum = 0;
        
        for (int bit = 0; bit < digits; bit++) {
            ll mask = 1LL << bit;
            ll ones = 0;
            for (ll j = cur; j < end; j++) {
                if (j & mask) ones++;
            }
            if (ones) {
                ll pwr = pow_mod(10, digits - 1 - bit);
                ll add = (ones % MOD) * pwr % MOD;
                sum = (sum + add) % MOD;
            }
        }
        
        res = ((res * mult) % MOD + sum) % MOD;
        cur *= 2;
        digits++;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << solve(n) << '\n';
    }
}