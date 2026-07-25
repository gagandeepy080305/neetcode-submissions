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
public://optimal but here we use iterative approach
//T.C. - O(height)
//S.C. - O(1)
//In solution 1 - we use recursive appraoch so it takes extra space but even that is optimal
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root!=NULL){
            if(p->val < root->val && q->val < root->val){
                root=root->left;
            }
            else if(p->val > root->val && q->val > root->val){
                root=root->right;
            }
            else{
            return root;
            }
        }
        return NULL;
    }
};
