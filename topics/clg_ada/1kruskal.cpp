#include <bits/stdc++.h>

using namespace std;

int findParent(vector<int> &parent, int component)
{
	if (parent[component] == component)
		return component;

	return parent[component] = findParent(parent, parent[component]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
	int n = parent.size();
	u = findParent(parent, u);
	v = findParent(parent, v);

	if (rank[u] < rank[v])
		parent[u] = v;
	else if (rank[u] > rank[v])
		parent[v] = u;
	else
	{
		parent[v] = u;
		rank[v]++;
	}
}

void kruskalAlgo(vector<vector<int>> &edges)
{
	int n = edges.size();
	// sort edges on the basis of thier weight 
	sort(edges.begin(), edges.end(), [](const auto &v1, const auto &v2)
		 { return v1[2] < v2[2]; });

	vector<int> parent(n);
	vector<int> rank(n, 0);
	for (int i = 0; i < n; i++)
		parent[i] = i;

	int minCost = 0;
	cout << "Following are the edges in the constructed MST: \n";
	for (int i = 0; i < n; i += 1)
	{
		int v1 = findParent(parent, edges[i][0]);
		int v2 = findParent(parent, edges[i][1]);
		int wt = edges[i][2];

		if (v1 != v2)
		{
			unionSet(v1, v2, parent, rank);
			minCost += wt;
			cout << edges[i][0] << "--" << edges[i][1] << "==" << wt << endl;
		}
	}

	cout << "Minimum cost of spanning Tree: " << minCost << endl;
}
int main()
{

	vector<vector<int>> edges = {{0, 1, 10},
								 {0, 2, 6},
								 {0, 3, 5},
								 {1, 3, 15},
								 {2, 3, 4}};
	kruskalAlgo(edges);
	return 0;
}