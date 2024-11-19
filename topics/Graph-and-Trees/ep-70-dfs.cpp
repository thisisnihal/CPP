#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define ppb           pop_back
#define sz            size()
#define ed            "\n"

#define TxtIO         freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

/* author: nihal136nihal@gmail.com
* created at 2023-05-23 01:00:29 */
using namespace std;

const int N = 1e5+10;
bool visited[N];
vector<int> g[N];

// T.C = O(V+E)
void dfs(int vertex) {

    // if (visited[vertex]) return; //equialent to `if (visited[child])continue;` in the loop.
    cout << "v: " << vertex << ed;
    visited[vertex] = true;
    
    // Take action on vertex after entering the vertex
    for (int child : g[vertex]) {
            
         cout << "p: " << vertex << ", c: " << child << ed;
        if (visited[child])continue;
        // Take action on child before entering the child node
        dfs(child);
        // Take action on child after exiting the child node
    }   
    // Take action on vertex before exiting the vertex
}



int main()
{
    TxtIO

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1); // comment it for directed graph
    }
    dfs(1);


    return 0;
}


/*
INPUT:
6 9
1 3
1 5
3 5
3 4
3 6
3 2
2 3
4 6
5 6
OUTPUT:
v: 1
p: 1, c: 3
v: 3
p: 3, c: 1
p: 3, c: 5
v: 5
p: 5, c: 1
p: 5, c: 3
p: 5, c: 6
v: 6
p: 6, c: 3
p: 6, c: 4
v: 4
p: 4, c: 3
p: 4, c: 6
p: 6, c: 5
p: 3, c: 4
p: 3, c: 6
p: 3, c: 2
v: 2
p: 2, c: 3
p: 2, c: 3
p: 3, c: 2
p: 1, c: 5





#ifndef ONLINE_JUDGE
 
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
 
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
 
#endif


*/

















/*
idk why the below code is not working

const int N = 1e5+10;

bool visited[N];
bool dfs (int );
auto g;

bool dfs(int vertex) {

    // if (visited[vertex]) return;
    cout << "vertex:" << vertex << ed;
    visited[vertex] = true;
    for (int child : g[vertex]) {

        if (visited[child]) continue;

        dfs(child);
    }
}

vector<pair<int,int>>* getGraphUsingList()
{
   int vertices, edges;
   cin >> vertices >> edges;
    
    // vector<int> graph[edges]; //-> for graph of equal weight.
    vector<pair<int,int> > graph[edges];  // each value stores vertex value and its weight between

    for (int i = 1; i < edges ; i++)
    {
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        graph[v1].push_back({v2, weight});
        graph[v2].push_back({v1, weight});
    }
    
    return graph;
}

int main()
{
    g = getGraphUsingList();


    return 0;
}






*/