class Solution {
public:// Optimal without constructing an adjacency list
// Time Complexity: O(V * E)
// Space Complexity: O(V)
//where V - Vertices and E - Edges of the graph
    bool isCycleDFS(int src ,vector<bool>&vis,vector<bool>&recPath,vector<vector<int>>& prerequisites){
        vis[src] = true;
        recPath[src] = true;

        for(int i=0;i<prerequisites.size();i++){//find all neighbours
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];

            if(u==src){
                if(!vis[v]){
                    if(isCycleDFS(v,vis,recPath,prerequisites))return true;
                }
                else if(recPath[v])return true;
            }
        }
        recPath[src] = false;
        return false;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses,false);
        vector<bool>recPath(numCourses,false);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(isCycleDFS(i,vis,recPath,prerequisites))return false;
            }
        }
        return true;
    }
};
