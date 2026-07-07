class Solution {
public://better force
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row==0)return false;
        int col = matrix[0].size();
        for (int i=0;i<row;i++){
            if(target >= matrix[i][0] && target <= matrix[i][col-1]){
                int left = 0,right = col-1;
                while(left<=right){
                    int mid = (left+right)/2;
                    if(matrix[i][mid]==target)return true;
                    else if(matrix[i][mid] > target )right = mid-1;
                    else left = mid+1;
                }
            }
        }
        return false;
    }
};
