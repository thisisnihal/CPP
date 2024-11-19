#include <bits/stdc++.h>

using namespace std;

int findParent(int i, vector<int> &parent)
{
	if (parent[i] == -1)
		return i;
	// recursively finds parent
	return parent[i] = findParent(parent[i], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
	u = findParent(u, parent);
	v = findParent(v, parent);

	if (rank[u] < rank[v])
		parent[u] = v;
	else if (rank[u] > rank[v])
		parent[v] = u;
	else
	{
		parent[v] = u;
		rank[u]++;
	}
}

void kruskalAlgo(vector<vector<int>> &edges)
{
	int n = edges.size();
	// sort edges on the basis of thier weight 
	sort(edges.begin(), edges.end(), [](const auto &v1, const auto &v2)
		 { return v1[2] < v2[2]; });

	vector<int> parent(n, -1);
	vector<int> rank(n, 0);
	

	int minCost = 0;
	cout << "Following are the edges in the constructed MST: \n";
	for (int i = 0; i < n; i += 1)
	{
		int v1 = findParent(edges[i][0], parent);
		int v2 = findParent(edges[i][1], parent);
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