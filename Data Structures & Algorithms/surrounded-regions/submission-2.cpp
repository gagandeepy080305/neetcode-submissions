class Solution {
private:
    void dfs(vector<vector<char>>& board, int r, int c) {
        int rows = board.size();
        int cols = board[0].size();

        if (r < 0 || c < 0 || r >= rows || c >= cols || board[r][c] != 'O') {
            return;
        }

        // Mark the connected 'O' as safe (temporarily as '#')
        board[r][c] = '#';

        // Traverse all 4 directions
        dfs(board, r + 1, c);
        dfs(board, r - 1, c);
        dfs(board, r, c + 1);
        dfs(board, r, c - 1);
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;

        int rows = board.size();
        int cols = board[0].size();

        // 1. Traverse the boundaries and mark all connected 'O's as '#'
        for (int r = 0; r < rows; ++r) {
            if (board[r][0] == 'O') dfs(board, r, 0);
            if (board[r][cols - 1] == 'O') dfs(board, r, cols - 1);
        }

        for (int c = 0; c < cols; ++c) {
            if (board[0][c] == 'O') dfs(board, 0, c);
            if (board[rows - 1][c] == 'O') dfs(board, rows - 1, c);
        }

        // 2. Iterate through the entire board to capture surrounded 'O's and restore safe '#'s
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X'; // Captured
                } else if (board[r][c] == '#') {
                    board[r][c] = 'O'; // Restore to original
                }
            }
        }
    }
};