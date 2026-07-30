class Solution {
public://optimal
//T.C. - O(n*m)
//S.C. - O(n*m)
    int dir[5] = {-1, 0, 1, 0, -1};//search for all 4 direction using one array

    void dfs(int i, int j, vector<vector<int>>& heights,
             vector<vector<bool>>& vis, int n, int m) {

        vis[i][j] = true;

        for (int k = 0; k < 4; k++) {
            int ni = i + dir[k];
            int nj = j + dir[k + 1];

            if (ni >= 0 && ni < n &&
                nj >= 0 && nj < m &&
                !vis[ni][nj] &&
                heights[ni][nj] >= heights[i][j]) {

                dfs(ni, nj, heights, vis, n, m);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        // Pacific Ocean (Top Row)
        for (int j = 0; j < m; j++) {
            if (!pacific[0][j])
                dfs(0, j, heights, pacific, n, m);
        }

        // Pacific Ocean (Left Column)
        for (int i = 0; i < n; i++) {
            if (!pacific[i][0])
                dfs(i, 0, heights, pacific, n, m);
        }

        // Atlantic Ocean (Bottom Row)
        for (int j = 0; j < m; j++) {
            if (!atlantic[n - 1][j])
                dfs(n - 1, j, heights, atlantic, n, m);
        }

        // Atlantic Ocean (Right Column)
        for (int i = 0; i < n; i++) {
            if (!atlantic[i][m - 1])
                dfs(i, m - 1, heights, atlantic, n, m);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};