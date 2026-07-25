/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public://optimal but not Binary tree appraoch or correctly said recursive approach 
    unordered_map<int, int> mp;

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
                     int& preIdx, int left, int right) {

        if (left > right)
            return NULL;

        // Current root
        TreeNode* root = new TreeNode(preorder[preIdx]);

        // Find root position in inorder in O(1)
        int inIdx = mp[preorder[preIdx]];

        preIdx++;

        // Build left subtree
        root->left = helper(preorder, inorder,
                            preIdx, left, inIdx - 1);

        // Build right subtree
        root->right = helper(preorder, inorder,
                             preIdx, inIdx + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Store inorder indices
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        int preIdx = 0;

        return helper(preorder, inorder,
                      preIdx, 0, inorder.size() - 1);
    }
};