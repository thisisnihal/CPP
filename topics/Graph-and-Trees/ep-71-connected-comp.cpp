// #include <bits/stdc++.h>
// #define ll long long
// #define ull unsigned long long
// #define ld long double
// #define pb push_back
// #define sz size()
// #define ed "\n"
// /* author: nihal136nihal@gmail.com
//  * created at 2023-05-24 15:49:57 */
// using namespace std;

// // need to more clean although solution is corrct to question:
// // https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/

// const int N = 1e5 + 10;
// vector<int> g[N];

// unordered_map<int, bool> vis;

// int final_ct = 0;
// int ct = 0;

// vector<int> comp[N];
// int conn_comp = 0;

// void dfs(int v)
// {
//     // if (vis[v]) return;
//     vis[v] = true;
//     for (int child : g[v])
//     {
//         if (vis[child])
//             continue;

//         comp[conn_comp].push_back(child);
//         ct++;
//         dfs(child);
//     }
// }

// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//     int n, e;
//     cin >> n >> e;
//     for (int i = 0; i < e; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//         vis[u] = false;
//         vis[v] = false;
//     }
//     for (int i = 1; i <= n; i++)
//         if (vis.find(i) == vis.end())
//             vis[i] = false;

//     for (auto pr : vis)
//     {
//         if (pr.second == false)
//         {
//             if (pr.second == false and g[pr.first].size() != 0)
//             {
//                 ct = 0;
//                 dfs(pr.first);
//                 final_ct += ct;
//             }
//             comp[conn_comp].push_back(pr.first);
//             conn_comp++;
//         }
//     }

//     cout << "ct = " << ct << ed;
//     cout << "final_ct = " << final_ct << ed;
//     cout << "conn_comp = " << conn_comp << ed;
//     cout << "[\n";
//     for (auto e : comp)
//     {
//         for (auto e1 : e)
//         {
//             cout << e1 << " ";
//         }
//         if (e.size() > 0)
//             cout << ed;
//     }
//     cout << "]\n";
//     cout << "end" << ed;
// }




/**
 * @brief METHOD 1. (by me)
 * 
 */
// METHOD 1. (by me)

// #include <bits/stdc++.h>
// #define ll long long
// #define ull unsigned long long
// #define ld long double
// #define pb push_back
// #define sz size()
// #define ed "\n"

// using namespace std;

// const int N = 1e5 + 10;
// vector<int> g[N];
// unordered_map<int, bool> vis;
// int conn_comp = 0;

// void dfs(int v)
// {
//     vis[v] = true;
//     for (int child : g[v])
//     {
//         if (vis[child]) continue;

//         dfs(child);
//     }
// }

// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//     int n, e;
//     cin >> n >> e;

//     for (int i = 0; i < e; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//         vis[u] = false;
//         vis[v] = false;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         if (vis.find(i) == vis.end())
//             vis[i] = false;
//     }

//     for (auto it : vis)
//     {

//         if (it.second == false and g[it.first].size() == 0) conn_comp++;
//         else if (it.second == false and g[it.first].size() != 0) {
//             dfs(it.first);
//             conn_comp++;
//         }
//     }

//     cout << conn_comp << ed;

// }




/**
 * @brief METHOD 1. (by LUV)
 * 
 */

// METHOD 2. (by luv)

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define sz size()
#define ed "\n"
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
unordered_map<int, bool> vis;
int conn_comp = 0;
vector<vector<int>> cc; // array of connected components.
vector<int> current_cc; // it holds one connected component.

void dfs(int v)
{
    vis[v] = true;
    current_cc.push_back(v);
    for (int child : g[v])
    {
        if (vis[child]) continue;
       
        dfs(child);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);
        conn_comp++;
    }
        

    cout << "no of connected components = " << conn_comp << ed;
    for (auto c_cc : cc) {
        for (int vertex : c_cc) {
            cout << vertex << " ";
        }
        cout << ed;
    }

}


