class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int matrixDimension = matrix.size();
        if(matrixDimension<=1)return;
        for(int rowIdx = 0;rowIdx<matrixDimension;++rowIdx){
            for(int collIdx = rowIdx+1;collIdx<matrixDimension;++collIdx){
                swap(matrix[rowIdx][collIdx],matrix[collIdx][rowIdx]);
            }
        }

        for(auto& currRow : matrix){
            reverse(currRow.begin(),currRow.end());
        }
    }
};
