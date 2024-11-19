#include <bits/stdc++.h>
using namespace std;

void printMST(vector<int> &parent, vector<vector<int>> &graph)
{
	cout << "Edge \tWeight\n";
	int minCost = 0;
	for (int i = 1; i < graph.size(); i++)
	{
		cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
		minCost += graph[i][parent[i]];
	}
	cout << "Minimum cost of spanning Tree: " << minCost << endl;
}

int minDist(vector<int> &dist, vector<bool> &visited)
{
	int mn = INT_MAX, mnIdx;
	for (int i = 0; i < dist.size(); i++)
	{
		if (!visited[i] && dist[i] < mn)
		{
			mn = dist[i];
			mnIdx = i;
		}
	}
	return mnIdx;
}

void primMST(vector<vector<int>> &graph)
{
	int n = graph.size();
	vector<int> parent(n, -1);
	vector<int> dist(n, INT_MAX);
	vector<bool> visited(n, false);
	dist[0] = 0;

	for (int count = 0; count < n - 1; count++)
	{
		int u = minDist(dist, visited);
		visited[u] = true;

		for (int v = 0; v < n; v++)
		{
			if (graph[u][v] && !visited[v] && graph[u][v] < dist[v])
			{
				dist[v] = graph[u][v];
				parent[v] = u;
			}
		}
	}

	printMST(parent, graph);
}

int main()
{
	vector<vector<int>> graph = {{0, 2, 0, 6, 0},
								 {2, 0, 3, 8, 5},
								 {0, 3, 0, 0, 7},
								 {6, 8, 0, 0, 9},
								 {0, 5, 7, 9, 0}};

	primMST(graph);
	return 0;
}
