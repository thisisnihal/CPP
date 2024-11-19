#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"


/* author: nihal136nihal@gmail.com
* created at 2023-05-23 01:00:29 */
using namespace std;


// CHECKS IF THE GRAPH IS CYCLIC OR NOT.

const int N = 1e5+10;
bool visited[N];
vector<int> g[N];
bool isLoopExists = false;
// T.C = O(V+E)
// in this case 
bool dfs(int vertex, int parent) {

    visited[vertex] = true;
    for (int child : g[vertex]) {

        if (visited[child] && child == parent) continue;    
        if (visited[child]) return true;
       
        isLoopExists |= dfs(child, vertex);
    }
    return isLoopExists;   
}



int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1); // comment it for directed graph
    }
    bool isLoopExists = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i]) continue;
        if (dfs(i, 0)) {
            isLoopExists = true;
            break;
        }
    }
    cout << isLoopExists << ed;

    


    return 0;
}
