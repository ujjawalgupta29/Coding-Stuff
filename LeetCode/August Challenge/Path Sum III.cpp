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
    
    int counts = 0;
    
    void check(TreeNode* root, int sum, int curr_sum)
    {   
        if(root == NULL)
            return;
        
        curr_sum += root->val;
        
        if(sum == curr_sum)
        {
            counts++;
        }
        
        check(root->left, sum, curr_sum);
        check(root->right, sum, curr_sum);
    }
    
    void traverse(TreeNode* root, int sum)
    {
        if(root == NULL)
            return;
        
        check(root, sum, 0);
        traverse(root->left, sum);
        traverse(root->right, sum);
    }
    
    int pathSum(TreeNode* root, int sum) {
        traverse(root, sum);
        return counts;
    }
};