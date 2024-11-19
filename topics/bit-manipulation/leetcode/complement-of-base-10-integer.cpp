#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-05-13 11:50:40 */
using namespace std;
void printBinary(int num)
{
    for (int i = 10; i >= 0; i--)
        cout << ((num >> i) & 1);
    cout << "\n";
}
int fmsb(int n) {
    int a = 0x7FFFFFFF;
    

}
int main()
{
    int t = 1;
    // cin >> t;
    while(t--) {
        int n = 17;
        printBinary(n);
        int i = 4; // ith bit.
        // i = fmsb(n);
        printBinary(i);
        int b = ( n | ( (1 << i )-1 ) );
        printBinary(b);

        int comp = n ^ b;
        printBinary(comp);

    }
    return 0;
}