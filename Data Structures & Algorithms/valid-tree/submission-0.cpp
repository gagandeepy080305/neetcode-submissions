class Solution {
public:

    bool dfs(int node,int parent,vector<vector<int>>&adj,vector<bool>&vis){
        vis[node]=true;

        for(int neighbour : adj[node]){
            if(!vis[neighbour]){
                if(dfs(neighbour,node,adj,vis))return true;
            }
            else if(neighbour != parent)return true;
        }
        return false;
    }


    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1)return false;

        vector<vector<int>>adj(n);

        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool>vis(n,false);

        if(dfs(0,-1,adj,vis))return false;

        for(int i=0;i<n;i++){
            if(!vis[i])return false;
        }

        return true;
    }
};
