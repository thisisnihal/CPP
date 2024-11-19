// floyd algorithm
#include<bits/stdc++.h>
 
using namespace std;
 
#define inf (1<<8)
 
void printSolution(vector<vector<unsigned int>>& dist){
	cout <<"The following matrix shows the shortest distance between every pair of vertces\n";
	for (int i = 0; i < dist.size(); i += 1)
	{
		for (int j = 0; j < dist.size(); j += 1)
		{
			if (dist[i][j] >= inf) printf("%7s", "INF");
			else printf("%7d", dist[i][j]);
		}
		cout << endl;
	}
}
 
void floydWarshall(vector<vector<unsigned int>>& dist) {
	int n = dist.size();
	for (int i = 0; i < n; i += 1)
	{
		for (int j = 0; j < n; j += 1)
		{
			for (int k = 0; k < n; k += 1)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	printSolution(dist);
}
 
int main() {
 
	vector<vector<unsigned int>> graph = {{0, 5, inf, 10},
								{inf, 0, 3, inf},
								{inf, inf, 0, 1},
								{inf, inf, inf, 0}};
	floydWarshall(graph);
	return 0;
}
