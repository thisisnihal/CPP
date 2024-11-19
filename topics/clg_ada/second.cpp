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

int maxPointsInsideSquare(vector<vector<int>> &points, string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        points[i].push_back(s[i]);
    }
    sort(points.begin(), points.end(), [](const auto &v1, const auto &v2)
         { return (v1[0] * v1[0] + v1[1] * v1[1]) < (v2[0] * v2[0] + v2[1] * v2[1]); });
    int ans = 0;
    unordered_set<int> st;

    int x = abs(points[0][0]), y = abs(points[0][1]);
    int mxc = max(x, y);

    for (auto v : points)
    {
        int x = abs(v[0]), y = abs(v[1]), c = v[2];
        
        cout << "mxc = " << mxc << ed;
        cout << x << "," << y << " : " << v[2] << ed;
        if (mxc >= x && mxc >= y && st.find(c) == st.end())
        {
            ans++;
            st.insert(c);
            mxc = abs(max(max(x, y), mxc));
        }
        else
        {
            break;
        }
    }

    return ans;
}
void solve()
{
    vector<vector<int>> v = {{-1, -4}, {16, -8}, {13, -3}, {-12, 0}}; // {{2, 2}, {-1, -2}, {-4, 4}, {-3, 1}, {3, -3}};
    string s = "abda"; // "abdca";
    int ans = maxPointsInsideSquare(v, s);
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