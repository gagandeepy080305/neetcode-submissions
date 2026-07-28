class Solution {
public: // Optimal
    // Time Complexity: O(m * n * 3^L)
    //   m = number of rows
    //   n = number of columns
    //   L = length of the word
    //
    // Space Complexity: O(L)
    //   Recursion stack depth is at most the length of the word.
    bool search(vector<vector<char>>& board, string& word,int i , int j , int r , int c , int k){
        if(k == word.size())return true;//base case
        if(i<0 || j<0 || i>=r || j>=c || board[i][j]!=word[k])return false;//Invalid cases
        char ch = board[i][j];
        board[i][j] = '#';//marking the cell where we searched
        bool op1 = search(board,word,i-1,j,r,c,k+1);//check upwards
        bool op2 = search(board,word,i+1,j,r,c,k+1);//check downwards
        bool op3 = search(board,word,i,j-1,r,c,k+1);//check left
        bool op4 = search(board,word,i,j+1,r,c,k+1);//check right
        board[i][j] = ch;//unmarking the cell where we searched or also known as backtrack
        return op1||op2||op3||op4;
    }



    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0;i<rows;i++){
            for(int j = 0 ; j<cols;j++){
                if(board[i][j] == word[0]){
                    if( search(board,word,i,j,rows,cols,0))return true;
                }
            }
        }
        return false;//if word does not exists
    }
};
