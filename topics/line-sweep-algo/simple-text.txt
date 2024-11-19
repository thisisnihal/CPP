#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-09-27 00:45:35 */
using namespace std;

int main()
{
    int a = 10, b = 20;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "a = " << a << " b = " << b << ed;

    long long abc;
    int k = sizeof(abc);
    cout << "k = " << k;
    return 0;
}