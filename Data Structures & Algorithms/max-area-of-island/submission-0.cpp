class Solution {
public://optimal
// T.C. - O(n × m)
// S.C. - O(n × m)

    int dfs(int i , int j ,vector<vector<bool>>&vis,vector<vector<int>>& grid,int n , int m){

        if(i<0||j<0||i>=n||j>=m||vis[i][j]||grid[i][j]==0)return 0;//base case

        vis[i][j] = true;
        int up = dfs(i-1,j,vis,grid,n,m);//top neighbour
        int right = dfs(i,j+1,vis,grid,n,m);//right neighbour
        int down = dfs(i+1,j,vis,grid,n,m);//bottom neighbour
        int left = dfs(i,j-1,vis,grid,n,m);//left neighbour

        return 1+up+down+left+right; //return area of island
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int area = dfs(i,j,vis,grid,n,m);
                    maxi = max(maxi,area);
                }
            }
        }
        return maxi;
    }
};
