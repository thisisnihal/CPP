#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define sz size()
#define ed "\n"

using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
int depth[N];

// in this case
void dfs(int vertex, int parent = 0)
{
    for (int child : g[vertex])
    {
        if (child == parent) continue;

        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);

       
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1); // comment it for directed graph
    }

    dfs(1);
    int mx_depth = -1;
    int mx_depth_node;
    for (int i = 1; i <= n; i++)
    {
        if (mx_depth < depth[i]) {
            mx_depth = depth[i];
            mx_depth_node = i;
        }
        depth[i] = 0; // reset depth, cause we need to run dfs again in below loop;
    }

    dfs(mx_depth_node);
    mx_depth = -1;
    for (int i = 1; i <= n; i++)
    {
        if (mx_depth < depth[i]) {
            mx_depth = depth[i];
        }
    }
    cout << "max_depth = " << mx_depth << ed;
    return 0;
}

/*
INPUT
13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11

OUTPUT


*/