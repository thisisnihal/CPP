#include <bits/stdc++.h>
using namespace std;

void topologicalSortUtil(int v, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st)
{
    visited[v] = true;
    for (int i : adj[v])
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, st);
    st.push(v);
}

void topologicalSort(vector<vector<int>> &adj, int v)
{
    stack<int> st;
    vector<bool> visited(v, false);
    for (int i = 0; i < v; ++i)
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    int v = 6;
    vector<vector<int>> edges = {{5, 0}, {5, 2}, {2, 3}, {3, 1}, {4, 0}, {4, 1}};
    vector<vector<int>> adj(v);
    for (auto &edge : edges)
        adj[edge[0]].push_back(edge[1]);
    topologicalSort(adj, v);
    return 0;
}
