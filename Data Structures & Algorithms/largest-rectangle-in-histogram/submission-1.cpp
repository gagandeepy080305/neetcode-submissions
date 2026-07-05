class Solution {
public://optimal
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>rs(n);//right smallest nearest
        vector<int>ls(n);//left smallest nearest
        stack<int>s;
        //right smaller
        for(int i=n-1;i>=0;i--){
            while(s.size()>0 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            rs[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        while(!s.empty()){
            s.pop();
        }


        //left smaller
        for(int i =0 ;i<n;i++){
            while(s.size()>0 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            ls[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            int w = rs[i] - ls[i] - 1;
            int currArea = heights[i] * w;
            ans = max(ans,currArea);
        }
        return ans;
    }
};
