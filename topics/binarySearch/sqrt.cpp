#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 36;
    int lo = 1, hi = n, mid;

    while (hi - lo > 1)
    {
        mid = (hi+lo)/2;
        int val = mid * mid;
        if (val == n) {
            cout << mid << endl;
            break;
        } else if (val < n) {
            lo = mid + 1;
        } else hi = mid - 1;
    }
    cout << hi << "," << lo << "," << mid <<  endl;
}