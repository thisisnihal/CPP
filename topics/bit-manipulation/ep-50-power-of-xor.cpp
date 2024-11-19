#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-05-10 11:35:34 */
using namespace std;
void swap_using_xor()
{
    // xor is commutative and associative
    // 1 ^ 1 = 0 ; 0 ^ 0 = 0
    // 1 ^ 0 = 1 ; 0 ^ 1 = 1
    int a = 5, b = 6;

    a = a ^ b;
    b = b ^ a;
    // b = b ^ (a ^ b) ==> b ^ b ^ a ==> a
    a = a ^ b;
    // a = (a ^ b) ^ a ==> a ^ a ^ b ==> b

    cout << a << " " << b << ed;
}
int main()
{
    swap_using_xor();
    return 0;
}