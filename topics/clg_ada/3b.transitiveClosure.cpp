#include <iostream>
#include <vector>
using namespace std;

#define V 4

void printSolution(const vector<vector<int>>& reach);

void transitiveClosure(vector<vector<int>>& graph) {
    vector<vector<int>> reach = graph;

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    printSolution(reach);
}

void printSolution(const vector<vector<int>>& reach) {
    cout << "Following matrix is transitive closure of the given graph\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j)
                cout << "1 ";
            else
                cout << reach[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> graph = { {1, 1, 0, 1},
                                  {0, 1, 1, 0},
                                  {0, 0, 1, 1},
                                  {0, 0, 0, 1} };

    transitiveClosure(graph);
    return 0;
}
