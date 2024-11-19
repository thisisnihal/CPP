#include<bits/stdc++.h>
using namespace std;

#define R 6
#define C 5
typedef struct Triplet
{
    int row, col, val;
} triplet;


triplet* create(int m, int n) {
    triplet* transpose = (triplet*) malloc(sizeof(triplet) * m * n );
}

triplet* transpose_matrix(triplet* matrix, int m) {
    triplet* transpose = (triplet*) malloc(sizeof(triplet) * m);

    


}

int main()
{
    
    triplet a = {0, 2, 5};
    cout << a.row << " " << a.col << " " << a.val << "\n";
    
}











/*

int n = matrix[0].size();
// converting input matrix as Transpose matrix
for (int i = 0; i < n; i++)
{
    for (int j = 0; j < i + 1; j++)
    {
        swap(matrix[i][j], matrix[j][i]);
    }
}

*/