class Solution {
public://better sol with in built binary search function 
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row==0)return false;
        int col = matrix[0].size();
        for (int i=0;i<row;i++){
            if(target >= matrix[i][0] && target <= matrix[i][col-1]){
                int left = 0,right = col-1;
                if(binary_search(matrix[i].begin() , matrix[i].end(),target)){
                    return true;
                }
            }
        }
        return false;
    }
};
