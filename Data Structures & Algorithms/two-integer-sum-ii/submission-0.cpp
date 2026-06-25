class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int right = n-1;
        int left = 0;
        vector<int>res;
        while(left<right){
            int sum = numbers[left]+numbers[right];
            if(sum==target){
                res.push_back(left+1);
                res.push_back(right+1);
                break;
            }
            else if(sum>target){
                right--;
            }
            else left++;
        }
        return res;
    }
};
