class Solution {
public://optimal
//T.C. - O(V+E)
//S.C. - O(V+E)

    void dfs(int node,vector<vector<int>>&adj,vector<bool>&vis){
        vis[node]=true;

        for(int neighbour : adj[node]){
            if(!vis[neighbour]){
                dfs(neighbour,adj,vis);
            }
        }
    }


    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool>vis(n,false);
        int components = 0;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                components++;
                dfs(i,adj,vis);
            }
        }
        return components;
    }
};
