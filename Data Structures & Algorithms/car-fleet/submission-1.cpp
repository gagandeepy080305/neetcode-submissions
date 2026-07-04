class Solution {
public://stack solution
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>cars;
        int n = position.size();
        for(int i = 0;i<n;i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end(),[](auto &a , auto &b){return a.first> b.first;});
        stack<double>st;
        double maxTime = 0.0;
        for(auto car : cars){
            double time  = (double)(target-car.first)/car.second;
            if(!st.empty() && time<=st.top()){
                continue;
            }
            else st.push(time);
        }
        return st.size();
    }
};
