struct Node{
    Node* links[26];
    bool flag = false;
    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
    }

    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
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

class PrefixTree {
private: Node* root;

public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {//Inserts a word into the trie
        Node* node = root;//T.C. - O(L) and S.C. - O(L)
        for(int i=0 ; i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);//moves to reference trie
        }
        node->setEnd();
    }
    

    //Returns if the word is in the trie
    bool search(string word) {//T.C. - O(L) and S.C. - O(1)
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    //Returns if there is any word in the trie starts with given word
    bool startsWith(string prefix) { //T.C. - O(L) and S.C. - O(1)
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i]))return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};
