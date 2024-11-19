#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-10-27 15:31:25 */
using namespace std;

int sum_of_digits(int n) {
    if (n < 10) return n;
    return sum_of_digits(n/10) + n%10;
}

void f(int n) {
    if (n == 0) return;
    cout << n << ed;
    // f(n--);  // it'll cause the infinte recursion cause it will call f(n) again and again cause n-- will be performed later.
    f(--n); // it will work fine.
}

// returns the reverse digits in n
int rev(int n) {
    int nd = (int) log10(n) + 1;
    if (n < 10) return n;
    return rev(n/10) + (n%10) * pow(10, nd-1);
}

// returns the count of zeros in n
int ct0(int n) {
    if (n == 0) return 1;
    if (n < 10) return 0;
    if (n%10 == 0) return 1 + ct0(n/10);
    return ct0(n/10);
}

// prints the count of zeros in n
void ct0(int n, int ct) {
    if (n == 0) { cout << 1 << ed; return; }
    if (n < 10) { cout << ct << ed; return; }
    if (n%10 == 0) ct0(n/10, 1+ct);
    else ct0(n/10, ct);
}

int main()
{
    int n;
    cin >> n;

    // cout << sum_of_digits(n) << ed;

    // cout << ed;
    // f(n);

    // cout << rev(n) << ed;
    cout << ct0(n) << ed; 
    
    int ct = 0;
    // ct0(n, ct);
    vector<int> memo;
    
    return 0;
}