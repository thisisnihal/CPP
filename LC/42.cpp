#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define ulld unsigned long long double
#define pb push_back
#define ppb pop_back
#define sz size()
#define ed "\n"
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

using namespace std;

int trap(vector<int> &height)
{
    int l = 0, r = height.size() - 1;
    int rmax = 0, lmax = 0;
    int water = 0;
    while (l < r) {
        if (height[l] < height[r]) {
            if (lmax <= height[l]) lmax = height[l];
            else water += lmax - height[l];
            printf("# %d, %d, %d, %d, %d\n", l, lmax, r, rmax, height[l]);
            l++;
        } else {
            if (rmax <= height[r]) rmax = height[r];
            else water += rmax - height[r];
            printf("* %d, %d, %d, %d, %d\n",  l, lmax, r, rmax, height[l]);
            r--;
        }
    }
    return water;
}
int main()
{
    vector<int> h = {0,1,0,2,1,0,1,3,2,1,2,1};
    int ans = trap(h);
    cout << "ans = " << ans << ed;
    return 0;
}

/*

index=0,1,2,3,4,5,6,7,8,9,10,11
arr =[0,1,0,2,1,0,1,3,2,1,2,1]

| l | r  | height[l] | height[r] | lmax | rmax | water added | total water |
| - | -- | ---------- | ---------- | ---- | ---- | ----------- | ----------- |
| 0 | 11 | 0          | 1          | 0    | 0    | 0           | 0           |
| 1 | 11 | 1          | 1          | 1    | 0    | 0           | 0           |
| 1 | 10 | 1          | 2          | 1    | 2    | 0           | 0           |
| 2 | 10 | 0          | 2          | 1    | 2    | 1           | 1           |
| 3 | 10 | 2          | 2          | 2    | 2    | 0           | 1           |
| 4 | 10 | 1          | 2          | 2    | 2    | 1           | 2           |
| 5 | 10 | 0          | 2          | 2    | 2    | 2           | 4           |
| 6 | 10 | 1          | 2          | 2    | 2    | 1           | 5           |
| 7 | 10 | 3          | 2          | 3    | 2    | 0           | 5           |
| 7 | 9  | 3          | 1          | 3    | 2    | 1           | 6           |
| 7 | 8  | 3          | 2          | 3    | 2    | 0           | 6           |
| 7 | 7  | 3          | 3          | 3    | 3    | 0           | 6           |

*/