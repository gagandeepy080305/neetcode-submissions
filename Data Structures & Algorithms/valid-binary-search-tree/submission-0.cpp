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
//S.C. - O(1)

    bool helper(TreeNode* root , TreeNode* mini , TreeNode* maxi){
        if(root==NULL)return true;
        if(mini!=NULL && root->val <= mini->val)return false;
        if(maxi!=NULL && root->val >= maxi->val)return false;
        return helper(root->left,mini,root) && helper(root->right,root,maxi);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root,NULL,NULL);
        
    }
};
