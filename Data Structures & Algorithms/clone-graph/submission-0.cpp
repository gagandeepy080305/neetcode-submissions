/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public://optimal
// T.C. - O(V + E)
// S.C. - O(V)
//V = Number of vertices (nodes)
//E = Number of edges

    Node* dfs(Node* curr , unordered_map<Node*,Node*>&mp){
        vector<Node*> neighbors;
        Node* clone = new Node(curr->val);
        mp[curr] = clone;
        for(auto it : curr->neighbors){
            if(mp.find(it)!=mp.end()){
                neighbors.push_back(mp[it]);
            }
            else
                neighbors.push_back(dfs(it,mp));
        }
        clone->neighbors=neighbors;
        return clone;
    }


    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
        unordered_map<Node*,Node*>mp;
        if(node->neighbors.size()==0){//If only one node graph
            Node* clone = new Node(node->val);
            return clone;
        }
        return dfs(node,mp);
    }
};
