class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, char dig) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == dig) return false;
            if (board[row][i] == dig) return false;
        }

        int srow = 3 * (row / 3);
        int scol = 3 * (col / 3);
        for (int i = srow; i < srow + 2; i++) {
            for (int j = scol; j < scol + 3; j++) {
                if (board[i][j] == dig) return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char dig = '1'; dig <= '9'; dig++) {
                        if (isSafe(i, j, board, dig)) {
                            board[i][j] = dig;
                            if (solve(board)) return true;
                            board[i][j] = '.'; 
                        }
                    }
                    return false; 
                }
            }
        }
        return true; 
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
