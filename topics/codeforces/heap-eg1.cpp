#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2024-04-07 13:57:52 */
using namespace std;


void insert(T element, int *n) {
    int i = ++(*n);
    while (i != 1 && item.key > heap[i/2].key) {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = item;
}

void solve()
{
    
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >>t;
    while(t--)solve();
    return 0;
}

