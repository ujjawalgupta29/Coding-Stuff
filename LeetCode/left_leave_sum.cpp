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
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        left_sum(root);
        return  sum;
    }
    
    void left_sum(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        if(root)
        {
            if(root->left)
            {
                if(root->left->right == NULL && root->left->left == NULL)
                    sum += root->left->val;
            }
        }
        
        left_sum(root->left);
        left_sum(root->right);
    }
};