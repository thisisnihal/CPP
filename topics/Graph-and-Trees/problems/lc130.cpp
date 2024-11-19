#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define sz size()
#define ed "\n"
/* author: nihal136nihal@gmail.com
 * created at 2023-06-08 23:35:25 */
using namespace std;

vector<vector<bool>> vis;


void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &board) 
{
    int r = board.size();
    int c = board[0].size();
    if (i < 0 || j < 0 || i >= r || j >= c) return;
    if (board[i][j] == 'X') return;
    if (vis[i][j]) return;

    vis[i][j] = true;
    dfs(i - 1, j, vis, board);
    dfs(i + 1, j, vis, board);
    dfs(i, j - 1, vis, board);
    dfs(i, j + 1, vis, board);


}

void solve(vector<vector<char>> &board)
{
    int r = board.size(), c = board[0].size();
    vis.resize(r, vector<bool>(c, false));

    for (int i = 0; i < c; i++)
    {
        if (board[0][i] == 'O') dfs(0, i, vis, board);
        if (board[r-1][i] == 'O') dfs(r-1, i, vis, board);
    }
    for (int i = 0; i < r; i++)
    {
        if (board[i][0] == 'O') dfs(i, 0, vis, board);
        if (board[i][c-1] == 'O') dfs(i, c-1, vis, board);
    }

    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (!vis[i][j] and board[i][j] == 'O') board[i][j] = 'X';
        }
    }
    
}

int main()
{

    vector<vector<char>> board = {{'X','X','X','X'},
                                  {'X','O','O','X'},
                                  {'X','X','O','X'},
                                  {'X','O','X','X'}};
    solve(board);

    for (auto &v : board) {
        for (auto c : v) cout << c << " ";
    cout << ed;
    }
    return 0;
}