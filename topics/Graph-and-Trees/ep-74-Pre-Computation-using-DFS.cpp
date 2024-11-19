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

int subtree_sum[N];
int even_ct[N];

// in this case
void dfs(int vertex, int parent = 0)
{

    if (vertex % 2 == 0) even_ct[vertex]++;
    subtree_sum[vertex] += vertex;
    for (int child : g[vertex])
    {

        if (child == parent) continue;

        dfs(child, vertex);

        subtree_sum[vertex] += subtree_sum[child];
        even_ct[vertex] += even_ct[child];
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

    for (int i = 1; i <= n; i++)
    {
        cout << subtree_sum[i] << " " << even_ct[i] << ed;
    }

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