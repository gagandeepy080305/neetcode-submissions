class Solution {
public://optimal
//T.C. - O(W * L +m*n* 4^L)
//S.C. - O(W*L+L)

    class Node{
        public:
        Node* links[26];
        bool flag ;
        string word;
        Node(){
            for(int i=0;i<26;i++){
                links[i] = NULL;
            }
            flag = false;
            word="";
        }

        bool containKey(char ch){
            return links[ch-'a']!=NULL;
        }

        void put(char ch , Node* node){
            links[ch-'a'] = node;
        }

        Node* get(char ch){
            return links[ch-'a'];
        }

        void setEnd(){
            flag = true;
        }

        bool isEnd(){
            return flag;
        }

    };

    Node* root;

    void insert(string word){
        Node* node = root;

        for(char ch : word){
            if(!node->containKey(ch))node->put(ch,new Node());
            node = node->get(ch);
        }
        node->setEnd();
        node->word = word;
    }

    void dfs(vector<vector<char>>& board , int i , int j,Node* node ,vector<string>&ans){
        char ch = board[i][j];

        if(ch=='#' || !node->containKey(ch))return;

        node = node->get(ch);

        if(node->isEnd()){
            ans.push_back(node->word);
            node->flag = false;
        }
        board[i][j] = '#';

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        for(int k = 0;k<4;k++){
            int ni = i+dx[k];
            int nj = j+dy[k];

            if(ni>=0 && nj>=0 && ni<board.size() && nj<board[0].size()){
                dfs(board,ni,nj,node,ans);
            }
        }
        board[i][j]=ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();
        for(string word : words){
            insert(word);
        }
        vector<string>ans;

        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(board,i,j,root,ans);
            }
        }
        return ans;
    }
};
