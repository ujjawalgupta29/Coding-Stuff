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
    
    bool cal_sum(TreeNode* root, int pre, int sum)
    {
        if(!root)
        {
            return 0;
        }
        
        if(root->left == NULL && root->right == NULL)
        {
            pre += root->val;
            return pre == sum;                
        }
        
        pre += root->val;
        
        return (cal_sum(root->left, pre, sum) || cal_sum(root->right, pre, sum));
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        return cal_sum(root, 0, sum);
    }
};