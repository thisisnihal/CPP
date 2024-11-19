import random
import numpy as np

def is_valid(board, row, col, num):
    for i in range(9):
        if board[row][i] == num or board[i][col] == num:
            return False
    start_row, start_col = 3 * (row // 3), 3 * (col // 3)
    for i in range(start_row, start_row + 3):
        for j in range(start_col, start_col + 3):
            if board[i][j] == num:
                return False
    return True

def find_empty_location(board):
    for i in range(9):
        for j in range(9):
            if board[i][j] == 0:
                return (i, j)
    return None

def solve_sudoku(board):
    empty_loc = find_empty_location(board)
    if not empty_loc:
        return True
    row, col = empty_loc

    for num in range(1, 10):
        if is_valid(board, row, col, num):
            board[row][col] = num
            if solve_sudoku(board):
                return True
            board[row][col] = 0
    return False

def generate_full_sudoku():
    board = np.zeros((9, 9), dtype=int)
    for k in range(0, 9, 3):
        fill_3x3_subgrid(board, k, k)
    solve_sudoku(board)
    return board

def fill_3x3_subgrid(board, row, col):
    nums = list(range(1, 10))
    random.shuffle(nums)
    for i in range(3):
        for j in range(3):
            board[row + i][col + j] = nums.pop()

def check_unique_solution(board):
    board_copy = board.copy()
    solutions = []

    def find_all_solutions(board):
        empty_loc = find_empty_location(board)
        if not empty_loc:
            solutions.append(board.copy())
            return
        row, col = empty_loc
        for num in range(1, 10):
            if is_valid(board, row, col, num):
                board[row][col] = num
                find_all_solutions(board)
                board[row][col] = 0
        if len(solutions) > 1:
            return

    find_all_solutions(board_copy)
    return len(solutions) == 1

def remove_numbers(board, difficulty):
    empty_cells = [(i, j) for i in range(9) for j in range(9) if board[i][j] != 0]
    attempts = difficulty
    while attempts > 0 and empty_cells:
        row, col = random.choice(empty_cells)
        backup = board[row][col]
        board[row][col] = 0
        if not check_unique_solution(board):
            board[row][col] = backup
        else:
            empty_cells.remove((row, col)) 
            attempts -= 1 
    return board



def generate_sudoku(difficulty):
    full_board = generate_full_sudoku()
    temp_full_board = full_board.copy()
    puzzle = remove_numbers(full_board, difficulty)
    return (puzzle, temp_full_board)

# Example usage
difficulty  = int(input("Enter difficulty: "))  # Adjust the difficulty level
print("----Printing Sudoku------\n")
sudoku_puzzle, full_board = generate_sudoku(difficulty)
print(np.array(sudoku_puzzle))
print("\n-------Solution------\n")

solved_board = np.array(full_board)
print(solved_board)
