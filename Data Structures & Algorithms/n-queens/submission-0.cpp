class Solution {
public://optimal
//T.C. - O(n!)
//S.C. - O(n^2)

    bool isSafe(vector<string>& board,int row ,int col , int n){//O(n)
        //horizontal
        for(int j=0;j<n;j++){
            if(board[row][j]=='Q')return false;
        }

        //vertical
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q')return false;
        }

        //left Diagonal
        for(int i=row , j=col ; i>=0 && j>=0;i-- , j--){
            if(board[i][j]=='Q')return false;
        }

        //right Diagonal
        for(int i=row,j=col;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q')return false;
        }
        return true;
    }

    void nQueens(vector<string>& board,int row ,int n,vector<vector<string>>&ans){

        if(row==n){
            ans.push_back(board);
            return;
        }

        //row is fixed so check in which col to place queen 
        for(int j=0;j<n;j++){
            if(isSafe(board,row,j,n)){
                board[row][j] = 'Q';
                nQueens(board,row+1,n,ans);//recurrsive call to place n queens
                board[row][j] = '.';//backtrack step
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));//Initialize empty n*n board
        vector<vector<string>>ans;
        nQueens(board,0,n,ans);
        return ans;
    }
};
