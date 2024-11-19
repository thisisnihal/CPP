#include <bits/stdc++.h>
#define ll            long long
#define ull           unsigned long long
#define ld            long double
#define pb            push_back
#define sz            size()
#define ed            "\n"
/* author: nihal136nihal@gmail.com
* created at 2023-05-25 00:55:01 */
using namespace std;

// https://leetcode.com/problems/flood-fill/


void dfs(int i, int j, int initColor, int newColor, vector<vector<int>>& image)
{
    int n = image.size();
    int m = image[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m) return;
    if (image[i][j] != initColor) return;

    image[i][j] = newColor;
    dfs(i-1, j, initColor, newColor, image);
    dfs(i+1, j, initColor, newColor, image);
    dfs(i, j-1, initColor, newColor, image);
    dfs(i, j+1, initColor, newColor, image);
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    
    int initColor = image[sr][sc];
    if (initColor != newColor) 
        dfs(sr, sc, initColor, newColor, image);
    return image;
}

int main()
{
// #ifndef ONLINE_JUDGE
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// #endif
    
    return 0;
}

