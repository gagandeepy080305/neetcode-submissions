class Solution {
public://optimal
//T.C. - O(E)
//S.C. - O(N)

    vector<int>parent,rank;

    int find(int node){
        if(parent[node]==node)return node;

        return parent[node] = find(parent[node]);
    }

    bool Union(int u , int v){
        int pu = find(u);
        int pv = find(v);

        if(pu==pv)return false;

        if(rank[pu] < rank[pv])parent[pu] = pv;
        else if(rank[pu] > rank[pv])parent[pv] = pu;
        else{
            parent[pv] = pu;
            rank[pu]++;
        } 
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        parent.resize(n+1);
        rank.resize(n+1,0);

        for(int i = 1;i<=n;i++){
            parent[i]=i;
        }

        for(auto &edge : edges){
            if(!Union(edge[0],edge[1]))return edge;
        }
        return {};
    }
};
