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
   public:
    int ans = 0;
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        int currDiam = leftHeight + rightHeight;
        ans=max(currDiam,ans);
        return 1+max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }
};
