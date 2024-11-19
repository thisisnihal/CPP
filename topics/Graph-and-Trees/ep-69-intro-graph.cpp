#include <bits/stdc++.h>
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-05-19 02:35:18 */
using namespace std;


// Declare Graph using Adjacency matrix
// space complexity : O(n^2) where n = veretices..
// n != 10^5 or n <= 10^3
vector<vector<int>> getGraphUsingMatrix()
{
    int vertices, edges;
    cin >> vertices >> edges;
    // int graph[vertices][edges];
    vector<vector<int>> graph(vertices+1, vector<int>(edges+1,0));
   
    for (int i = 1; i <= edges; i++)
    {
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        graph[v1][v2] = weight;
        graph[v2][v1] = weight; // comment this line for directed graph
    }
    
    return graph;
}



// Declare Graph using Adjacency List
// space complexity : O(v+E) 
vector<pair<int,int>>* getGraphUsingList()
{
   int vertices, edges;
   cin >> vertices >> edges;
    
    // vector<int> graph[edges]; //-> for graph of equal weight.
    vector<pair<int,int> > graph[edges];  // each value stores vertex value and its weight between

    for (int i = 1; i <= edges ; i++)
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

    vector<vector<int>> matrixGraph = getGraphUsingMatrix();
    int i = 1, j = 3, wt = 1;
    // Graph using Adjacency Matrix takes O(1) for check if it connected or not.
    if (matrixGraph[i][j] == wt) {
        cout << "vertices(" << i << "," << j << ")" << " is connected" << endl; 
    }


    
    vector<pair<int,int>>* listGraph = getGraphUsingList();
    // Graph using Adjacency List takes O(n) for check if it connected or not.
    for (pair<int,int> child : *listGraph) {
        if (child.first == j) {
            // connected
           cout <<  child.second << endl ;
        }
    }

    return 0;
}


/*
INPUT VALUES

*/





/*



    it'll create an array of row size = n+1 and col size = m+1; it will init all values with 0
    int graph[row][col];
    vector< vector<int> > graph (row, vector<int>(col+1, init_value));
    for 2d vector : https://stackoverflow.com/questions/17663186/initializing-a-two-dimensional-stdvector


*/