/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int sum = 0) {
        if(!root)
            return 0;
        sum = (sum << 1) | root->val;
        
        return (root->left == root->right) ? sum : 
        (sumRootToLeaf(root->left, sum) + sumRootToLeaf(root->right, sum));
        
    }
};