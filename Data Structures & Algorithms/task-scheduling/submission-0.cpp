class Solution {
public://optimal 
//T.C. - O(n^2) in worst case , but this is better since in brute force it is O(n^3)
//S.C. - O(n)
    int leastInterval(vector<char>& tasks, int n) {
        //step 1 : count frequency of each task
        vector<int> freq(26,0);
        for(auto task : tasks)freq[task-'A']++;

        //step 2 : build a maxHeap based on frequency
        priority_queue<int>maxHeap;
        for(int f : freq){
            if(f>0)maxHeap.push(f);
        }

        //step 3 : Process the tasks
        int time = 0;
        while(!maxHeap.empty()){
            vector<int>temp;
            for(int i = 0 ;i<n+1;i++){
                if(!maxHeap.empty()){
                    temp.push_back(maxHeap.top());
                    maxHeap.pop();
                }
            }

            for(int freq : temp){
                if(--freq > 0){
                    maxHeap.push(freq);
                }
            }

            //step 4 : update time 
            time+= maxHeap.empty() ? temp.size() : n+1;
        }
        return time ;
    }
};
