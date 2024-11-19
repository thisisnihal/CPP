#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2024-04-08 20:36:51 */
using namespace std;

int minRectanglesToCoverPoints(vector<vector<int>> &points, int w)
{
    sort(points.begin(), points.end(), [](const auto &v1, const auto &v2)
         { return v1[0] < v2[0]; });
    int minrect = 1;
    int x0 = points[0][0];

    // int x1 = x0 + w;

    for (vector<int> point : points)
    {

        if (point[0] > x0 + w)
        {
            x0 += w;
            minrect++;
        }
    }

    return minrect;
}

void solve()
{
    vector<vector<int>> v = {{2, 1}, {1, 0}, {1, 4}, {1, 8}, {3, 5}, {4, 6}};
    int ans = minRectanglesToCoverPoints(v, 2);
    cout << "ans=" << ans << ed;
}

int main()
{

    solve();
    return 0;
}

// for (auto v : points) {
//     cout << v[0] <<"," << v[1] << ed;
// }