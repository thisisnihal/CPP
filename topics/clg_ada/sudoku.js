function isValid(board, row, col, num) {
    for (let i = 0; i < 9; ++i) {
        if (board[row][i] === num || board[i][col] === num) {
            return false;
        }
    }
    const startRow = 3 * Math.floor(row / 3);
    const startCol = 3 * Math.floor(col / 3);
    for (let i = startRow; i < startRow + 3; ++i) {
        for (let j = startCol; j < startCol + 3; ++j) {
            if (board[i][j] === num) {
                return false;
            }
        }
    }
    return true;
}

function findEmptyLocation(board) {
    for (let i = 0; i < 9; ++i) {
        for (let j = 0; j < 9; ++j) {
            if (board[i][j] === 0) {
                return [i, j];
            }
        }
    }
    return null;
}

function solveSudoku(board) {
    const emptyLoc = findEmptyLocation(board);
    if (!emptyLoc) {
        return true;
    }
    const [row, col] = emptyLoc;

    for (let num = 1; num <= 9; ++num) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

function generateFullSudoku() {
    const board = Array.from({ length: 9 }, () => Array.from({ length: 9 }, () => 0));
    for (let k = 0; k < 9; k += 3) {
        fill3x3Subgrid(board, k, k);
    }
    solveSudoku(board);
    return board;
}

function fill3x3Subgrid(board, row, col) {
    const nums = Array.from({ length: 9 }, (_, idx) => idx + 1);
    shuffle(nums);
    let idx = 0;
    for (let i = row; i < row + 3; ++i) {
        for (let j = col; j < col + 3; ++j) {
            board[i][j] = nums[idx++];
        }
    }
}

function shuffle(array) {
    for (let i = array.length - 1; i > 0; --i) {
        const j = Math.floor(Math.random() * (i + 1));
        [array[i], array[j]] = [array[j], array[i]];
    }
}

function checkUniqueSolution(board) {
    const boardCopy = JSON.parse(JSON.stringify(board));
    const solutions = [];

    function findSolutions(board) {
        const emptyLoc = findEmptyLocation(board);
        if (!emptyLoc) {
            solutions.push(board.map(row => [...row]));
            return;
        }
        const [row, col] = emptyLoc;
        for (let num = 1; num <= 9; ++num) {
            if (isValid(board, row, col, num)) {
                board[row][col] = num;
                findSolutions(board);
                board[row][col] = 0;
            }
        }
        if (solutions.length > 1) {
            return;
        }
    }

    findSolutions(boardCopy);
    return solutions.length === 1;
}

function removeNumbers(board, difficulty) {
    const emptyCells = [];
    for (let i = 0; i < 9; ++i) {
        for (let j = 0; j < 9; ++j) {
            if (board[i][j] !== 0) {
                emptyCells.push([i, j]);
            }
        }
    }
    shuffle(emptyCells);
    
    let attempts = difficulty;
    while (attempts > 0 && emptyCells.length > 0) {
        const [row, col] = emptyCells.pop();
        const backup = board[row][col];
        board[row][col] = 0;
        if (!checkUniqueSolution(board)) {
            board[row][col] = backup;
        } else {
            attempts--;
        }
    }
    return board;
}

function generateSudoku(difficulty) {
    const fullBoard = generateFullSudoku();
    const tempFullBoard = fullBoard.map(row => [...row]);
    const puzzle = removeNumbers(fullBoard, difficulty);
    return [puzzle, tempFullBoard];
}

// Example usage
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question("Enter difficulty: ", (difficulty) => {
    const sudokuPuzzle = generateSudoku(parseInt(difficulty));
    function formatSudoku(board) {
        return board.map(row => row.join(' ')).join('\n');
    }
    
    // Example usage
    console.log("----Printing Sudoku------\n");
    console.log(formatSudoku(sudokuPuzzle[0]));
    console.log("\n-------Solution------\n");
    console.log(formatSudoku(sudokuPuzzle[1]));
    rl.close();
});
