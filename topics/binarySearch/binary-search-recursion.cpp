#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-05-26 21:02:01 */
using namespace std;

int search(int arr[], int target, int s, int e) {
    if (s > e) return -1;

    int m = s + (e-s)/2;
    if (arr[m] == target) return m;

    if (arr[m] < target) return search(arr, target, s, m-1);
    
    // if (arr[m] > target)
    return search(arr, target, m+1, e); 
}


int main()
{
    
    return 0;
}