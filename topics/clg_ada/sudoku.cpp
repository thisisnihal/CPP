#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <functional>

using namespace std;

// Function declarations
bool is_valid(vector<vector<int>> &board, int row, int col, int num);
pair<int, int> find_empty_location(vector<vector<int>> &board);
bool solve_sudoku(vector<vector<int>> &board);
vector<vector<int>> generate_full_sudoku();
void fill_3x3_subgrid(vector<vector<int>> &board, int row, int col);
bool check_unique_solution(vector<vector<int>> &board);
vector<vector<int>> remove_numbers(vector<vector<int>> &board, int difficulty);
pair<vector<vector<int>>, vector<vector<int>>> generate_sudoku(int difficulty);

// Function definitions

bool is_valid(vector<vector<int>> &board, int row, int col, int num)
{
    for (int i = 0; i < 9; ++i)
    {
        if (board[row][i] == num || board[i][col] == num)
        {
            return false;
        }
    }
    int start_row = 3 * (row / 3);
    int start_col = 3 * (col / 3);
    for (int i = start_row; i < start_row + 3; ++i)
    {
        for (int j = start_col; j < start_col + 3; ++j)
        {
            if (board[i][j] == num)
            {
                return false;
            }
        }
    }
    return true;
}

pair<int, int> find_empty_location(vector<vector<int>> &board)
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (board[i][j] == 0)
            {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

bool solve_sudoku(vector<vector<int>> &board)
{
    pair<int, int> empty_loc = find_empty_location(board);
    int row = empty_loc.first;
    int col = empty_loc.second;
    if (row == -1 && col == -1)
    {
        return true;
    }
    for (int num = 1; num <= 9; ++num)
    {
        if (is_valid(board, row, col, num))
        {
            board[row][col] = num;
            if (solve_sudoku(board))
            {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

vector<vector<int>> generate_full_sudoku()
{
    vector<vector<int>> board(9, vector<int>(9, 0));
    for (int k = 0; k < 9; k += 3)
    {
        fill_3x3_subgrid(board, k, k);
    }
    solve_sudoku(board);
    return board;
}

void fill_3x3_subgrid(vector<vector<int>> &board, int row, int col)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    shuffle(nums.begin(), nums.end(), default_random_engine());
    int idx = 0;
    for (int i = row; i < row + 3; ++i)
    {
        for (int j = col; j < col + 3; ++j)
        {
            board[i][j] = nums[idx++];
        }
    }
}

bool check_unique_solution(vector<vector<int>> &board)
{
    vector<vector<int>> board_copy = board;
    vector<vector<int>> solutions;

    function<void(vector<vector<int>> &)> find_all_solutions = [&](vector<vector<int>> &board)
    {
        pair<int, int> empty_loc = find_empty_location(board);
        int row = empty_loc.first;
        int col = empty_loc.second;
        if (row == -1 && col == -1)
        {
            solutions.push_back({});
            for (const auto &row : board)
            {
                solutions.back().insert(solutions.back().end(), row.begin(), row.end());
            }
            return;
        }
        for (int num = 1; num <= 9; ++num)
        {
            if (is_valid(board, row, col, num))
            {
                board[row][col] = num;
                find_all_solutions(board);
                board[row][col] = 0;
            }
        }
        if (solutions.size() > 1)
        {
            return;
        }
    };

    find_all_solutions(board_copy);
    return solutions.size() == 1;
}

vector<vector<int>> remove_numbers(vector<vector<int>> &board, int difficulty)
{
    vector<pair<int, int>> empty_cells;
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (board[i][j] != 0)
            {
                empty_cells.push_back({i, j});
            }
        }
    }
    shuffle(empty_cells.begin(), empty_cells.end(), default_random_engine());

    int attempts = difficulty;
    while (attempts > 0 && !empty_cells.empty())
    {
        int row = empty_cells.back().first;
        int col = empty_cells.back().second;
        empty_cells.pop_back();
        int backup = board[row][col];
        board[row][col] = 0;
        if (!check_unique_solution(board))
        {
            board[row][col] = backup;
        }
        else
        {
            attempts--;
        }
    }
    return board;
}

pair<vector<vector<int>>, vector<vector<int>>> generate_sudoku(int difficulty)
{
    vector<vector<int>> full_board = generate_full_sudoku();
    vector<vector<int>> temp_full_board = full_board;
    vector<vector<int>> puzzle = remove_numbers(full_board, difficulty);
    return make_pair(puzzle, temp_full_board);
}

int main()
{
    // Example usage
    int difficulty;
    cout << "Enter difficulty: ";
    cin >> difficulty; // Adjust the difficulty level
    cout << "----Printing Sudoku------\n\n";
    auto [sudoku_puzzle, full_board] = generate_sudoku(difficulty);

    // Output the puzzle
    for (const auto &row : sudoku_puzzle)
    {
        for (int cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << "\n-------Solution------\n\n";

    // Output the solution
    for (const auto &row : full_board)
    {
        for (int cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
