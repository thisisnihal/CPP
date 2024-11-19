#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2023-05-11 00:23:59 */
using namespace std;

const int M = 1e9 + 7;
int binExpRec(int a, int b)
{
    if (b == 0) return 1;
    int res = binExpRec(a, b / 2);
 //if b is odd
    if (b & 1) 
        return (a * ((res * 1LL * res) % M)) % M;
    else
        return ((res * 1LL * res) % M) % M;
}

/// @brief constraints : a <= 10^9, b <= 10^9, M <= 10^9+7
/// @param a int a <= 10^9
/// @param b int b <= 10^9
/// @return int (a to the power b) % M
int binExpIter(int a, int b) {
    int ans = 1;
    while (b) {
        if (b&1) ans = (ans * 1LL * a) % M;
        a = (a * 1LL * a) % M;
        b = b >> 1;
    }
    return ans; // TC = O(log(b))
}

const long long M1 = 1e18+7; 

long long binMultiply(long long a, long long b) {
    long long ans = 0;
    while (b > 0) {
        if (b&1) ans = (ans+a) % M1;
        a = (a + a) % M1;
        b = b >> 1;
    }
    return ans;
}


/// @brief constraints : a <= 10^18, b <= 10^18, M1 <= 10^18+7
/// @param a int a <= 10^18
/// @param b int b <= 10^18
/// @return int (a to the power b) % M1
long long largebinExpIter(long long a, long long b) {
    long long ans = 1;
    while (b > 0) {
        if (b&1) ans = binMultiply(ans, a);
        a = binMultiply(a, a);
        b = b >> 1;
    }
    return ans; // TC = O(log(b)^2)
}




int main()
{
    double d = 1e24;
    cout << fixed << setprecision(20) << d << ed; // = 999999999999999983222784.00000000000000000000

    cout << binExpRec(3, 9) << ed;
    cout << binExpIter(3, 9) << ed;
    cout << pow(3, 9) << ed;

    cout << "binExpIter(23134, 48742) = " << binExpIter(23134, 48742) << ed; 

    long long a = 1e16+9, b = 1e16+3;
    cout << "largebinExpIter(1e16+9, 1e16+3) = " << largebinExpIter(1e16+9, 1e16+3) << ed;

    

    return 0;
}


/** In the given function
 *  cout << binExpIter(3, 9) << ed;
 *  since bin(9) = 1001    = 1 x 2^3 + 0 x 2^2 + 0 x 2^1 + 1 x 2^0  = 8 + 0 + 0 + 1
 *  we will calculate : 3 ^(1001) = 3^8 x 3^0 x 3^0 x 3^1;
 */