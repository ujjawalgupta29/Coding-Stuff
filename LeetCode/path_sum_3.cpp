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
    int paths = 0;
    
    int pathSum(TreeNode* root, int sum) {
        
        if(!root)   return 0;
        paths += total_sum_till_now(root, 0, sum);
        int left = pathSum(root->left, sum);
        int right = pathSum(root->right, sum);
        return  paths;
    }
    
    int total_sum_till_now(TreeNode* root, int pre, int sum)
    {
        if(!root)   return 0;
        int current = pre + root->val;
        return (current == sum) + 
            total_sum_till_now(root->left, current, sum) + 
            total_sum_till_now(root->right, current, sum);
    }
};