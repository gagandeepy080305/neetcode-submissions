class WordDictionary {
public:

class Node{
    public :
        Node* links[26];
        bool flag;

        Node(){
            for(int i = 0 ;i<26;i++){
                links[i] =  NULL;
            }
            flag = false;
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

    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) { //T.C. - O(L) and space O(L)
        Node* node = root;

        for(char ch : word){
            if(!node->containKey(ch)){
                node->put(ch,new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool dfs(string &word , int index , Node* node){
        if(index == word.size())return node->isEnd();

        char ch = word[index];

        if(ch=='.'){
            for(int i=0;i<26;i++){
                if(node->links[i]!=NULL){
                    if(dfs(word,index+1,node->links[i]))return true;
                }
            }
            return false;
        }
        if(!node->containKey(ch))return false;

        return dfs(word,index+1,node->get(ch));
    }

    bool search(string word) {//T.C. - O(n) and space O(26^k * L)
        return dfs(word,0,root);
    }
};
