class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        int maxLength = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                maxLength = max(maxLength, dfs(matrix, i, j, memo));
            }
        }
        return maxLength;
    }

private:
    int dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& memo) {
        if (memo[r][c] != 0) return memo[r][c];
        
        int m = matrix.size(), n = matrix[0].size();
        int res = 1;
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && matrix[nr][nc] > matrix[r][c]) {
                res = max(res, 1 + dfs(matrix, nr, nc, memo));
            }
        }
        
        return memo[r][c] = res;
    }
};
