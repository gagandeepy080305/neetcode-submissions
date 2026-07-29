class Solution {
public://optimal
// T.C. - O(m × n)
// S.C. - O(m × n)

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;

        //push all tressure cells into queue
        for(int i = 0;i<n;i++){
            for(int j = 0 ;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        //Direction array
        int dr[] = {-1,0,1,0}; //row
        int dc[] = {0,1,0,-1}; //col

        //Multi-Source BFS
        while(!q.empty()){
            auto curr = q.front(); 
            q.pop();
            int row = curr.first;
            int col = curr.second;

            //explore all neighbour
            for(int k=0;k<4;k++){
                int nr = row+dr[k];
                int nc = col+dc[k];

                //visit only valid unvisited land cells(INF)
                if(nr>=0 && nc>=0 && nr<n && nc < m && grid[nr][nc] == INT_MAX){
                    //update distance
                    grid[nr][nc] = grid[row][col]+1;

                    //push into queue
                    q.push({nr,nc});
                }
            }
            
        }
    }
};
