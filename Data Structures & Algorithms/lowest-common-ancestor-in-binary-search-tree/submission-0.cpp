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
public://better solution , time is optimal but space can be improved
//T.C. - O(height)
//S.C. - O(height)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;
        if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left,p,q);
        }//left
        else if(p->val > root->val && q->val > root->val){
            
            return lowestCommonAncestor(root->right,p,q);
        }//right
        return root;
    }
};
