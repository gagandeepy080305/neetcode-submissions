/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public://optimal 
//T.C. - O(n)
//S.C. - O(height)
int cnt = 0;
void dfs(TreeNode* root , int maxTillNow){
    if(root==NULL)return ;
    if(root->val >= maxTillNow)cnt++;
    maxTillNow = max(maxTillNow,root->val);
    dfs(root->left,maxTillNow);
    dfs(root->right,maxTillNow);
}

    int goodNodes(TreeNode* root) {
        if(root==NULL)return 0;
        dfs(root,root->val);
        return cnt;
    }
};
