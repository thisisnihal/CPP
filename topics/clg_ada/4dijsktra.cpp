// dijsktra.cpp
#include<bits/stdc++.h>

using namespace std;

void printSolution(vector<int>& dist) {
	cout << "distance from src to -- \n";
	for (int i = 0; i < dist.size(); i += 1)
	{
		cout << i << " -- " << dist[i] << "\n";
	}
}

int minDist(vector<int>& dist, vector<bool>& visited) {
	int mn = INT_MAX, mnIdx, n = dist.size();
	for (int i = 0; i < n; i += 1)
	{
		if (!visited[i]  && dist[i] <= mn)
		{
			mn = dist[i];
			mnIdx = i;
		}
	}
	return mnIdx;
}

void dijkstra(vector<vector<int>>& graph, int src) {
	int n = graph.size();
	vector<int> dist(n, INT_MAX);
	vector<bool> visited(n, false);
	dist[src] = 0;
	for (int i = 0; i < n-1; i += 1)
	{
		int u = minDist(dist, visited);
		visited[u] = true;
		
		for (int v = 0; v < n; v += 1)
		{
			if (!visited[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
			{
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	printSolution(dist);
}

int main() {
	
	vector<vector<int>> graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
								  {4, 0, 8, 0, 0, 0, 0, 11, 0},
								  {0, 8, 0, 7, 0, 4, 0, 0, 2},
								  {0, 0, 7, 0, 9, 14, 0, 0, 0},
								  {0, 0, 0, 9, 0, 10, 0, 0, 0},
								  {0, 0, 4, 14, 10, 0, 2, 0, 0},
								  {0, 0, 0, 0, 0, 2, 0, 1, 6},
								  {8, 11, 0, 0, 0, 0, 1, 0, 7},
								  {0, 0, 2, 0, 0, 0, 6, 7, 0} };
	dijkstra(graph, 0);
	return 0;
}
