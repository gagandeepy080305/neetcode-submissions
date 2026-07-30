class Solution {
public://optimal
//T.C. - O(V+E)
//S.C. - O(V+E)

    void topologicalSort(int src , vector<bool>&vis ,stack<int>&s,vector<vector<int>>&prerequisites){
        vis[src] = true;

        for(int i=0;i<prerequisites.size();i++){
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];
            if(u==src){
                if(!vis[v]){
                    topologicalSort(v,vis,s,prerequisites);
                }
            }
        }
        s.push(src);
    }




    bool isCycle(int src,vector<bool>&vis,vector<bool>&recPath,vector<vector<int>>& prerequisites){
        vis[src] = true;
        recPath[src] = true;

        for(int i=0;i<prerequisites.size();i++){
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];

            if(u==src){
                if(!vis[v]){
                    if(isCycle(v,vis,recPath,prerequisites))return true;
                }
                else if(recPath[v])return true;
            }
        }
        recPath[src] = false;//backtrack
        return false;
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses,false);
        vector<bool>recPath(numCourses,false);
        vector<int>ans;

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(isCycle(i,vis,recPath,prerequisites))return ans;
            }
        }

        //topological sorting
        stack<int>s;
        vis.assign(numCourses,false);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                topologicalSort(i,vis,s,prerequisites);
            }
        }

        while(s.size() > 0){
            ans.push_back(s.top());
            s.pop();
        }

        return ans;

    }
};
