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
    
    int robUtil(TreeNode* root, int& lm, int& rm)
    {
        if(!root)
            return 0;
        
        int lm1 =0, lm2=0, rm1=0, rm2=0;
        
        lm = robUtil(root->left, lm1, rm1);
        rm = robUtil(root->right, lm2, rm2);
        
        return max(root->val + lm1 + rm1 + lm2 + rm2, lm + rm);
    }
    
    int rob(TreeNode* root) {
        int lm = 0, rm = 0;
        return robUtil(root, lm, rm);
    }
};