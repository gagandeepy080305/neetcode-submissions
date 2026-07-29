class Solution {
public://optimal
//T.C. - O(n*m)
//S.C. - O(n*m)

    void dfs(int row , int col , vector<vector<int>>&vis, vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();

        vis[row][col] = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for(int k = 0; k < 4; k++){
            int nr = row + dr[k];
            int nc = col + dc[k];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
               !vis[nr][nc] && board[nr][nc] == 'O'){
                dfs(nr, nc, vis, board);
            }
        }
    }


    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        //traverse first row and last row
        for(int j = 0; j < m; j++){
            if(!vis[0][j] && board[0][j] == 'O'){//first row
                dfs(0, j, vis, board);
            }

            if(!vis[n-1][j] && board[n-1][j] == 'O'){//last row
                dfs(n-1, j, vis, board);
            }
        }

        //traverse first col and last col
        for(int i = 0; i < n; i++){//first col
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i, 0, vis, board);
            }

            //last col
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(i, m-1, vis, board);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
};