#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-06-10 10:18:10 */
using namespace std;

// https://www.quora.com/How-do-I-implement-DFS-traversal-using-adjacency-matrix-in-a-C-program

void dfs(int i, vector<bool>& vis, vector<vector<int>>& graph)
{
    vis[i]=true; 
    for(int j=0;j<graph.size();j++) 
        if(!vis[j] && graph[i][j]==1) dfs(j, vis, graph); 
}


    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // it's an n x n matrix;
        int ans = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               if (!vis[j]) {
                dfs(j, vis, isConnected);
                ans++;
               }
            }
        }
        return ans;
    }

int main()
{
    vector<vector<int>> isConnected = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}}; 
                                    //   {{1,1,0},
                                    //    {1,1,0},
                                    //    {0,0,1}};
    int ans = findCircleNum(isConnected);
    cout << "ans = " << ans << ed;
    return 0;
}