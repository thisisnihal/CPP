#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-07-29 21:59:38 */
using namespace std;


double binExp(double a, long long b) {
    double ans = 1;
    while (b) {
        if (b&1) ans = (ans * 1LL * a);
        a = (a * 1LL * a);
        b = b >> 1;
    }
    return ans; // TC = O(log(b))
}

double myPow(double x, long long n) {
    
    if (x == 0) return 0;
    else if (n == 0) return 1;
    else if (n < 0){
        x = 1 / x;
        n = -n;
    }
    return binExp(x, n);
}


int main()
{
    
    return 0;
}   