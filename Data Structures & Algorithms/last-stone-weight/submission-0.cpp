class Solution {
public://optimal
//T.C. - O(n log n)
//S.C. - O(n)
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int,vector<int>,less<int>>maxHeap;
        for(int i : stones){
            maxHeap.push(i);
        }
        while(maxHeap.size() > 1){
            int s1 = maxHeap.top();
            maxHeap.pop();
            int s2 = maxHeap.top();
            maxHeap.pop();

            if(s1!=s2){
                maxHeap.push(s1-s2);
            }
        }
        return maxHeap.empty()?0:maxHeap.top();
    }
};
