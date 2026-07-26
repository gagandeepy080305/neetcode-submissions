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
//S.C. - O(n)

    int helper(TreeNode* root , int& maxi){
        if(root==NULL)return 0;

        int left = max(0,helper(root->left,maxi));//here if there is any negative path 
        int right = max(0,helper(root->right,maxi));// then taking 0 instead of that

        maxi = max(maxi , left+right+root->val);

        return root->val+max(left,right);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        helper(root,maxi);
        return maxi;
    }
};
