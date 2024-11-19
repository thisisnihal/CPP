#include<bits/stdc++.h>

using namespace std;


int minKey(vector<int>& key, vector<bool>& mstSet) {
	int mn = INT_MAX;
	int mnIdx;
	for (int i = 0; i < key.size(); i += 1)
	{
		if (mstSet[i] == false && key[i] < mn) {
			mn = key[i];
			mnIdx = i;
		}
	}
	return mnIdx;
}
void printMST(vector<vector<int>>& graph, vector<int>& parent) {
	cout << "Edge\tWeight\n";
	int minCost = 0;
	for (int i = 1; i < graph.size(); i += 1)
	{
		cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]]  << "\n";
		minCost += graph[i][parent[i]];
	}
	cout << "Minimum cost of spanning Tree: " << minCost << endl;

}
void primsMST(vector<vector<int>>& graph) {
	int n = graph.size();
	vector<int> parent(n);
	vector<int> key(n, INT_MAX);
	vector<bool> mstSet(n, false);
	
	key[0] = 0, parent[0] = -1;
	
	for (int i = 0; i < n-1; i += 1)
	{
		int u = minKey(key, mstSet);
		mstSet[u] = true;
		for (int v = 0; v < n; v += 1)
		{
			if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
			{
				parent[v] = u;
				key[v] = graph[u][v];
			}
		}
	}
	printMST(graph, parent);
}

int main() {
	
	vector<vector<int>> graph = { {0, 2, 0, 6, 0},
								  {2, 0, 3, 8, 5},
								  {0, 3, 0, 0, 7},
								  {6, 8, 0, 0, 9},
								  {0, 5, 7, 9, 0} };
	primsMST(graph);
	return 0;
}